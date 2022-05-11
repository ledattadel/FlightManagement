#include<iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include<iomanip>
#include <string>
#include <windows.h>
#include<fstream>
#define Enter 13
#define PASSWORD "abcdef"

using namespace std;
char* Pwd () {
     char S[40]; int i=0;
     while ((S[i]= getch()) != Enter ) 
     { printf ("%c", '*') ; i++ ; 
     }
     S[i]='\0';
     return S;
}

int CheckPwd () {
    int dem =0; 
    for ( dem =1 ; dem <=3 ; dem++)
    { printf( "Password :"); 
      if (strcmp(Pwd(),PASSWORD) ==0)   return 1;
      else printf ( "\nPassword sai. Hay nhap lai\n")  ; 
    }
    return 0;  
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X + 1, info.dwCursorPosition.Y + 1);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetWindow(int Width, int Height) 
    { 
    _COORD coord; 
    coord.X = Width; 
    coord.Y = Height; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = Height - 1; 
    Rect.Right = Width - 1; 

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
} 
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Thi?t l?p ch? d? hi?n th?, có fullscreen hay không
BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)
{
	typedef BOOL(WINAPI *SCDMProc_t) (HANDLE, DWORD, LPDWORD);
	SCDMProc_t SetConsoleDisplayMode;
	HMODULE hKernel32;
	BOOL bFreeLib = FALSE, ret;
	const char KERNEL32_NAME[] = "kernel32.dll";

	hKernel32 = GetModuleHandleA(KERNEL32_NAME);
	if (hKernel32 == NULL)
	{
		hKernel32 = LoadLibraryA(KERNEL32_NAME);
		if (hKernel32 == NULL)
			return FALSE;

		bFreeLib = true;
	}

	SetConsoleDisplayMode =
		(SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");
	if (SetConsoleDisplayMode == NULL)
	{
		SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
		ret = FALSE;
	}
	else
	{
		DWORD tmp;
		ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &tmp);
	}

	if (bFreeLib)
		FreeLibrary(hKernel32);

	return ret;
}

// Ð?t ch? d? FullScreen
void setFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}

// Thoát kh?i fullscreen
void exitFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}
//void XoaManHinhChinh()
//{
//	textcolor(7);
//	for (int i = 6; i < 36; i++)
//	{
//		for (int j = 51; j < 176; j++)
//		{
//			gotoxy(j, i);
//			cout << " ";
//		}
//	}
//} 

//void XoaManHinhTuyChon(int toadoX,int toadoY,int chieudai,int chieucao)
//{
//	textcolor(7);
//	for (int i = toadoY; i < chieucao+toadoY; i++)
//	{
//		for (int j = toadoX; j < toadoX + chieudai; j++)
//		{
//			gotoxy(j, i);
//			cout << " ";
//		}
//	}
//}
//void DeMuc(string x)
//{
//	SetColor(14);
//	gotoxy(51, 7);
//	cout << CanDeuChuoi(x, 126);
//	textcolor(7);
//}

void XoaLogo1(int toadoX, int toadoY)
{
	int h = toadoY;
	string str = "                                               ";
	while (h < 13 + toadoY)
	{
		gotoxy(toadoX, h++);
		cout << str << endl;
	}
}
void logo(int toadoX,int toadoy){
SetColor(1)	;
gotoxy(toadoX,toadoy);  cout<<"         _      _ _";
gotoxy(toadoX,toadoy+1);cout<<"    /   (_)    | (_)";
gotoxy(toadoX,toadoy+2);cout<<"   /     _ _ __| |_ _  __   _   ";
gotoxy(toadoX,toadoy+3);cout<<"  / /\   | | '__| | | '_  |/ _ | ";
gotoxy(toadoX,toadoy+4);cout<<" / ____ | | |  | | | | | |  __/ ";
gotoxy(toadoX,toadoy+5);cout<<"/_/    \_|_|_|  |_|_|_| |_|\___| ";
SetColor(255);
}
void XoaManHinhTrungTamNhanh()
{
	gotoxy(41,9); cout<<"                                                                                                                             ";
	gotoxy(41,10); cout<<"                                                                                                                            ";
	gotoxy(41,11); cout<<"                                                                                                                            ";
	gotoxy(41,12); cout<<"                                                                                                                            ";
	gotoxy(41,13); cout<<"                                                                                                                            ";
	gotoxy(41,14); cout<<"                                                                                                                            ";
	gotoxy(41,15); cout<<"                                                                                                                            ";
	gotoxy(41,16); cout<<"                                                                                                                            ";
	gotoxy(41,17); cout<<"                                                                                                                            ";
	gotoxy(41,18); cout<<"                                                                                                                            ";
	gotoxy(41,19); cout<<"                                                                                                                            ";
	gotoxy(41,20); cout<<"                                                                                                                            ";
	gotoxy(41,21); cout<<"                                                                                                                            ";
	gotoxy(41,22); cout<<"                                                                                                                            ";
	gotoxy(41,23); cout<<"                                                                                                                            ";
	gotoxy(41,24); cout<<"                                                                                                                            ";
	gotoxy(41,25); cout<<"                                                                                                                            ";
	gotoxy(41,26); cout<<"                                                                                                                            ";
	gotoxy(41,27); cout<<"                                                                                                                            ";
	gotoxy(41,28); cout<<"                                                                                                                            ";
	gotoxy(41,29); cout<<"                                                                                                                            ";
	gotoxy(41,30); cout<<"                                                                                                                            ";
	gotoxy(41,31); cout<<"                                                                                                                            ";
	gotoxy(41,32); cout<<"                                                                                                                            ";
	gotoxy(41,33); cout<<"                                                                                                                            ";
	gotoxy(41,34); cout<<"                                                                                                                            ";
	gotoxy(41,35); cout<<"                                                                                                                            ";
	gotoxy(41,36); cout<<"                                                                                                                            ";
	gotoxy(41,37); cout<<"                                                                                                                            ";
	gotoxy(41,38); cout<<"                                                                                                                            ";
	gotoxy(41,39); cout<<"                                                                                                                            ";
	gotoxy(41,40); cout<<"                                                                                                                            ";
	gotoxy(41,41); cout<<"                                                                                                                            ";
	gotoxy(41,42); cout<<"                                                                                                                            ";
	gotoxy(41,43); cout<<"                                                                                                                            ";

	
	
	
	
	
}
//void XoaThongBao2Nhanh(){
//	
//	gotoxy()
//	
//	
//}

void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauSet)
{
	SetColor(mauSet);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoxy(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoxy(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoxy(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoxy(chieudai + toadoX, i);
		cout << (char)179;
	}
	SetColor(7);
}
void XoaManHinhTuyChon(int toadoX,int toadoY,int chieudai,int chieucao)
{
	textcolor(7);
	for (int i = toadoY; i < chieucao+toadoY; i++)
	{
		for (int j = toadoX; j < toadoX + chieudai; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
}

//VeHCN(71,31+2,71,12,255);
void XoaManHinh3(){
	
	SetBGColor(0);
	SetColor(0);
	
		gotoxy(41,33);cout<<"                                                                                                                             ";
	gotoxy(41,34);cout<<"                                                                                                                             ";
	gotoxy(41,35);cout<<"                                                                                                                             ";
	gotoxy(41,36);cout<<"                                                                                                                             ";
	gotoxy(41,37);cout<<"                                                                                                                             ";
	gotoxy(41,38);cout<<"                                                                                                                             ";
	gotoxy(41,39);cout<<"                                                                                                                             ";
	gotoxy(41,40);cout<<"                                                                                                                             ";		
	gotoxy(41,41);cout<<"                                                                                                                             ";
	gotoxy(41,42);cout<<"                                                                                                                             ";
	gotoxy(41,43);cout<<"                                                                                                                             ";
	gotoxy(41,44);cout<<"                                                                                                                             ";
	gotoxy(41,45);cout<<"                                                                                                                             ";
	SetColor(255);
	
	
}


// 42,10,104,35
void XoaManHinhTrungTam(){
	

	SetBGColor(0);
	SetColor(0);
	gotoxy(41,10);cout<<"                                                                                                                             ";
	gotoxy(41,11);cout<<"                                                                                                                             ";
	gotoxy(41,12);cout<<"                                                                                                                             ";
	gotoxy(41,13);cout<<"                                                                                                                             ";
	gotoxy(41,14);cout<<"                                                                                                                             ";
	gotoxy(41,15);cout<<"                                                                                                                             ";
	gotoxy(41,16);cout<<"                                                                                                                             ";
	gotoxy(41,17);cout<<"                                                                                                                             ";
	gotoxy(41,18);cout<<"                                                                                                                             ";
	gotoxy(41,19);cout<<"                                                                                                                             ";
	gotoxy(41,20);cout<<"                                                                                                                             ";
	gotoxy(41,21);cout<<"                                                                                                                             ";
	gotoxy(41,22);cout<<"                                                                                                                             ";
	gotoxy(41,23);cout<<"                                                                                                                             ";
	gotoxy(41,24);cout<<"                                                                                                                             ";
	gotoxy(41,25);cout<<"                                                                                                                             ";
	gotoxy(41,26);cout<<"                                                                                                                             ";
	gotoxy(41,27);cout<<"                                                                                                                             ";
	gotoxy(41,28);cout<<"                                                                                                                             ";
	gotoxy(41,29);cout<<"                                                                                                                             ";
	gotoxy(41,30);cout<<"                                                                                                                             ";
	gotoxy(41,31);cout<<"                                                                                                                             ";
	gotoxy(41,32);cout<<"                                                                                                                             ";
	gotoxy(41,33);cout<<"                                                                                                                             ";
	gotoxy(41,34);cout<<"                                                                                                                             ";
	gotoxy(41,35);cout<<"                                                                                                                             ";
	gotoxy(41,36);cout<<"                                                                                                                             ";
	gotoxy(41,37);cout<<"                                                                                                                             ";
	gotoxy(41,38);cout<<"                                                                                                                             ";
	gotoxy(41,39);cout<<"                                                                                                                             ";
	gotoxy(41,40);cout<<"                                                                                                                             ";		
	gotoxy(41,41);cout<<"                                                                                                                             ";
	gotoxy(41,42);cout<<"                                                                                                                             ";
	gotoxy(41,43);cout<<"                                                                                                                             ";
	gotoxy(41,44);cout<<"                                                                                                                             ";
	gotoxy(41,45);cout<<"                                                                                                                             ";
	SetColor(255);
	
}
void XoaManHinhThongBao1(){
	SetBGColor(0);
	SetColor(0);

	
gotoxy(1,9); cout<<"                                       ";
gotoxy(1,10);cout<<"                                       ";
gotoxy(1,11);cout<<"                                       ";
gotoxy(1,12);cout<<"                                       ";
gotoxy(1,13);cout<<"                                       ";
gotoxy(1,14);cout<<"                                       ";
gotoxy(1,15);cout<<"                                       ";
gotoxy(1,16);cout<<"                                       ";
gotoxy(1,17);cout<<"                                       ";
gotoxy(1,18);cout<<"                                       ";
gotoxy(1,19);cout<<"                                       ";
gotoxy(1,20);cout<<"                                       ";
	
}
void XoaManHinhThongBao2(){
	
	gotoxy(1,22);cout<<"                                       ";
	gotoxy(1,23);cout<<"                                       ";
	gotoxy(1,24);cout<<"                                       ";
	gotoxy(1,25);cout<<"                                       ";
	gotoxy(1,26);cout<<"                                       ";
	gotoxy(1,27);cout<<"                                       ";
	gotoxy(1,28);cout<<"                                       ";
	gotoxy(1,29);cout<<"                                       ";
	gotoxy(1,30);cout<<"                                       ";
	gotoxy(1,31);cout<<"                                       ";
	gotoxy(1,32);cout<<"                                       ";
	gotoxy(1,33);cout<<"                                       ";
	gotoxy(1,34);cout<<"                                       ";
	gotoxy(1,35);cout<<"                                       ";
	gotoxy(1,36);cout<<"                                       ";
	gotoxy(1,37);cout<<"                                       ";
	gotoxy(1,38);cout<<"                                       ";
	gotoxy(1,39);cout<<"                                       ";
	gotoxy(1,40);cout<<"                                       ";
	gotoxy(1,41);cout<<"                                       ";
	gotoxy(1,42);cout<<"                                       ";
	gotoxy(1,43);cout<<"                                       ";
	gotoxy(1,44);cout<<"                                       ";
	
	
	
	
}

void XoaManHinhHuongDan(){
SetBGColor(0);
	SetColor(0);

gotoxy(1,1);cout<<"                                       ";
gotoxy(1,2);cout<<"                                       ";
gotoxy(1,3);cout<<"                                       ";
gotoxy(1,4);cout<<"                                       ";
gotoxy(1,5);cout<<"                                       ";
gotoxy(1,6);cout<<"                                      ";
gotoxy(1,7);cout<<"                                    ";
	
	
}


void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	textcolor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}
//Huong Dan
int MauNenHuongDan = 6;
void XoaHuongDan()
{
	textcolor(MauNenHuongDan);
	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 38; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}


void HuongDanMenuMain()
{
	
	ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 2);
	textcolor(188);
	cout << "HUONG DAN";
	textcolor(7);
	
	textcolor(MauNenHuongDan);
	cout << left;
	gotoxy(1, 4); 
	cout << setw(15) << "Nut Mui Ten:" << "De Dieu Khien";
	gotoxy(1, 5);
	cout << setw(15) << "Nut Enter  :" << "De Chon";
	gotoxy(1, 6);
	cout << setw(15) << "Nut Esc    :" << "De Thoat";
	textcolor(7);
}
void VeKhung(){
		XoaManHinhTuyChon(41,9,120,35); // xoa noi dung
			XoaManHinhTuyChon(1,1,38,9);// xoa thong bao
			XoaManHinhTuyChon(1,22,38,22);// xoa thong bao 2
			VeHCN( 0,0,40, 32+14,15); // ve man hinh thong bao doc
			VeHCN( 0,0,166, 14+32,15);// ve BG
			VeHCN( 0,0,166, 8,15);// ve man hinh ngang
}
void HuongDanThemDS()
{
	ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 2);
	textcolor(188);
	cout << "HUONG DAN";
	textcolor(7);
	
	textcolor(MauNenHuongDan);
	cout << left;
	gotoxy(1, 4);
	cout << setw(22) << "Luu y :             ";
	gotoxy(1, 5);
	cout << setw(22) << "- MB co 1 so hieu duy nhat";
	gotoxy(1, 6);
	cout << setw(22) << "- So cho ngoi > 20";
	textcolor(7);
}
void HuongDanSuaMB()
{
	ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 2);
	textcolor(188);
	cout << "HUONG DAN";
	textcolor(7);
	
	
	textcolor(MauNenHuongDan);
	gotoxy(10,12);
	cout << "< SUA MAY BAY >";
	cout << left;
	gotoxy(1, 4);
	cout << setw(22) << "Luu y :             ";
	gotoxy(1, 5);
	cout << setw(22) << "- MB co 1 so hieu duy nhat";
	gotoxy(1, 6);
	cout << setw(22) << "- So cho ngoi > 20";
	textcolor(7);
}
void HuongDanXoaMB()
{
	ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 2);
	textcolor(188);
	cout << "HUONG DAN";
	textcolor(7);
	
	textcolor(MauNenHuongDan);
	gotoxy(10,12);
	cout << "< XOA MAY BAY >";
	cout << left;
	gotoxy(1, 4);
	cout << setw(22) << "- May Bay dang co chuyen bay ";
	gotoxy(1, 5);
	cout << setw(22) << "khong the xoa";
	gotoxy(1, 6);
	cout << setw(22) << "- Xem danh sach MB tren man hinh";
	textcolor(7);
}
void HuongDanThemCB()
{
	
	
	ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 2);
	textcolor(188);
	cout << "HUONG DAN";
	textcolor(7);
//	logo(3,1);
	textcolor(MauNenHuongDan);
	cout << left;
	gotoxy(1, 4);
	cout << setw(22) << "Luu y :             ";
	gotoxy(1, 5);
	cout << setw(22) << "- Chuyen bay co 1 ma duy nhat";
	gotoxy(1, 6);
	cout << setw(22) << "- Thoi gian phai nhap chinh xac";
	textcolor(7);
}
void HuongDanXoaCB()
{
	ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 2);
	textcolor(188);
	cout << "HUONG DAN";
	textcolor(7);
	
	textcolor(MauNenHuongDan);
	gotoxy(10,12);
	cout << "< XOA CHUYEN BAY >";
	cout << left;
	gotoxy(1, 4);
	cout << setw(22) << "- Chuyen Bay co Hanh Khach dat ve";
	gotoxy(1, 5);
	cout << setw(22) << "khong the xoa";
	gotoxy(1, 6);
	cout << setw(22) << "- Xem danh sach CB tren man hinh";
	textcolor(7);
}
void HuongDanSuaCB()
{
	ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 2);
	textcolor(188);
	cout << "HUONG DAN";
	textcolor(7);
	textcolor(MauNenHuongDan);
	gotoxy(10,12);
	cout << "< SUA CHUYEN BAY >";
	textcolor(MauNenHuongDan);
	cout << left;
	gotoxy(1, 4);
	cout << setw(22) << "- Khong sua duoc khi co hanh khach";
	gotoxy(1, 5);
	cout << setw(22) << " dat ve.";
	gotoxy(1, 6);
	cout << setw(22) << "- Chuyen bay co 1 ma duy nhat";

	textcolor(7);
}
void HuongDanButton()
{
//		ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 1);
	textcolor(188);
	//textcolor(7);
		cout << "HUONG DAN";

	textcolor(MauNenHuongDan);
	cout << left;
	
	gotoxy(3, 3);
	cout << setw(1) << "Phim F1  : THEM";
	gotoxy(3, 4);
	cout << setw(1) << "Phim F2  : XOA";
	gotoxy(3, 5);
	cout << setw(1) << "Phim F3  : SUA";
	gotoxy(3, 6);
	cout << setw(1) << "Phim ESC : THOAT";
	
	textcolor(7);
}
void HuongDanButtonCB()
{
		//ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 1);
	textcolor(188);
//	textcolor(7);
		cout << "HUONG DAN";

	textcolor(MauNenHuongDan);
	cout << left;
	
	gotoxy(3, 3);
	cout << setw(1) << "Phim F1  : THEM";
	gotoxy(3, 4);
	cout << setw(1) << "Phim F2  : XOA";
	gotoxy(3, 5);
	cout << setw(1) << "Phim F3  : SUA";
	gotoxy(3, 6);
	cout << setw(1) << "Phim F4  : HUY CHUYEN BAY";
	gotoxy(3, 7);
	cout << setw(1) << "Phim ESC : THOAT";
	
	textcolor(7);
}
void HuongDanDSVe()
{
		//ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 1);
	textcolor(188);
//	textcolor(7);
		cout << "HUONG DAN";

	textcolor(MauNenHuongDan);
	cout << left;
	
	gotoxy(3, 3);
	cout << setw(1) << "- Tren 1 chuyen bay, 1 hanh khach";
	gotoxy(3, 4);
	cout << setw(1) << "  chi duoc mua 1 VE";
	gotoxy(3, 5);
	cout << setw(1) << "- Tim kiem MaCB trong danh sach";
	gotoxy(3, 6);
	cout << setw(1) << "  de dat VE";
	gotoxy(3, 7);
	cout << setw(1) << "- Nhan ESC de THOAT";
	
	textcolor(7);
}
void HuongDanVe()
{
		//ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 1);
	textcolor(188);
//	textcolor(7);
		cout << "HUONG DAN";

	textcolor(MauNenHuongDan);
	cout << left;
	
	gotoxy(3, 3);
	cout << setw(1) << "- Tren 1 chuyen bay, 1 hanh khach";
	gotoxy(3, 4);
	cout << setw(1) << "  chi duoc mua 1 VE";
	gotoxy(3, 5);
	cout << setw(1) << "- Tim kiem MaCB trong danh sach";
	gotoxy(3, 6);
	cout << setw(1) << "  de dat VE";
	gotoxy(3, 7);
	cout << setw(1) << "- Nhan ESC de THOAT";
	
	textcolor(7);
}
void Logo1(int toadoX, int toadoY)
{
	string str;
	ifstream FileIn;
	FileIn.open("input1.txt", ios::in);
	int h = toadoY;
	int mamau;
	while (true)
	{
		getline(FileIn, str);
		mamau = 10 + rand() % 6;
		SetColor(mamau);
		gotoxy(toadoX, h++);
		cout << str << endl;
		if (FileIn.eof())
		{
			break;
		}
	}
//	textcolor(7);
	FileIn.close();
}

void HuongDanMayBay()
{
	ToMauHCN( 14,1,11, 2,176);
	gotoxy(15, 2);
	textcolor(188);
	cout << "HUONG DAN";
	textcolor(7);
	
	XoaManHinhTuyChon(0,14,40,32+14);
	XoaManHinhTuyChon(1,1,40,8);
//	XoaManHinhTuyChon(1,1,40,40);
	VeHCN( 0,0,40, 14,15);
	VeHCN( 0,14,40, 32,15);
	VeHCN( 0,0,166, 14+32,15);
	
	textcolor(MauNenHuongDan);
	HuongDanButton();

		
		
}
void HuongDanSuaDG()
{
	textcolor(MauNenHuongDan);
	gotoxy(1, 4);
	cout << "";
	textcolor(7);
}

void ButtonDatVe(int color)
{
	gotoxy(154, 21); SetBGColor(color); 			 cout << "        ";
	gotoxy(154, 22); SetBGColor(color); SetColor(10);cout << "   F1   ";
	gotoxy(154, 23); SetBGColor(color);	SetColor(0);cout << " DAT VE ";
	gotoxy(154, 24); SetBGColor(color); cout <<"        ";
}
void ButtonHuyVe(int color)
{
gotoxy(154, 26); SetBGColor(color); 				cout << "        ";
	gotoxy(154, 27); SetBGColor(color); SetColor(12);cout <<"   F2   ";
	gotoxy(154, 28); SetBGColor(color); SetColor(0)	;cout << " HUY VE ";
	gotoxy(154, 29); SetBGColor(color); 	cout <<"        ";
	SetBGColor(0);SetColor(15);
}
void ButtonESC(int color)
{
	gotoxy(154, 31); SetBGColor(color); 			cout << "        ";
	gotoxy(154, 32); SetBGColor(color); SetColor(9);cout <<"  ESC   ";
	gotoxy(154, 33); SetBGColor(color); SetColor(0)	;cout <<" THOAT  ";
	gotoxy(154, 34); SetBGColor(color); 	         cout <<"        ";	
}
void Box_Menu_Ve(){
	
	VeHCN( 150,20,15, 15,255);
	ButtonDatVe(255);
	ButtonHuyVe(255);
	ButtonESC(255);
	
}
void Box_Huy_Ve() {

	SetBGColor(0);
	VeHCN( 14,24,24, 2,255);SetColor(255);gotoxy(3,25);cout<<"Ma Chuyen :";
	VeHCN( 14,26+1,24, 2,255);SetColor(255);gotoxy(3,27+1);cout<<"Chon Ghe  :";

}
void Box_YESNO(){
	
	
	
	
}


void Box_Dat_Ve(){
	
	SetBGColor(0);
	VeHCN( 14,24,24, 2,255);SetColor(255);gotoxy(3,25);cout<<"Ma Chuyen :";
	VeHCN( 14,26+1,24, 2,255);SetColor(255);gotoxy(3,27+1);cout<<"Chon Ghe  :";
	VeHCN( 14,28+2,24, 2,255);SetColor(255);gotoxy(3,29+2);cout<<"CMND      :";
	VeHCN( 14,30+3,24, 2,255);SetColor(255);gotoxy(3,31+3);cout<<"Ho        :";
	VeHCN( 14,32+4,24, 2,255);SetColor(255);gotoxy(3,33+4);cout<<"Ten       :";
	VeHCN( 14,34+5,24, 2,255);SetColor(255);gotoxy(3,35+5);cout<<"Gioi Tinh :";
}

void HuongDanXuat()
{
	textcolor(MauNenHuongDan);
	cout << left;
	gotoxy(1, 4);
	cout << setw(22) << "Nut Mui Ten Trai Phai :" << "De Chuyen Page";
	gotoxy(1, 5);
	cout << setw(22) << "Nut Esc " << ":De Tro Lai";
	textcolor(7);
}
void HuongDanXuatTheoTungTheLoai()
{
	textcolor(MauNenHuongDan);
	cout << left;
	gotoxy(1, 4);
	cout << setw(22) << "Nut Mui Ten Len Xuong :" << "De Dieu Khien Thanh Sang";
	gotoxy(1, 5);
	cout << setw(22) << "Nut Enter" << ":De Chon";
	gotoxy(1, 6);
	cout << setw(22) << "Nut Esc" << ":De Tro Lai";
	textcolor(7);
}
//==============================AN CO TRO MAN HINH CONSOLE=======================
void AnConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//==============================HIEN CON TRO MAN HINH CONSOLE================
void HienConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
