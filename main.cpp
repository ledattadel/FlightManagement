// THU VIEN

#include <iostream>
#include<windows.h>
#include <string.h>
#include <stdio.h>
#include "mylib.h"
#include <fstream>
#include <ctype.h>
#include <ctime>
#include <conio.h>
#include <sstream> 
#include <string>
#include<cstdlib>

// HEADER
#include"AVLhanhkhach.h"
 
//  DEFINE

#define MAXMB 300
#define MAXVE 30

#define MAX 100
#define UP 72
#define DOWN 80
#define BACKSPACE 8
#define ENTER 13
#define ESC 27
#define RIGHT 77
#define LEFT 75

#define F1 59
#define F2 60
#define F3 61
#define F4 62


#define ArrowRIGHT 27
#define ArrowLEFT 26
#define ArrowUP 25
#define ArrowDOWN 24

#define boxx 80 //Vi tri x bat dau cua box
#define boxy 14 //Vi tri y bat dau cua box
#define boxxCB 60
#define boxyCB 14
#define boxs 70 //Box size
#define tabx 75 // vi tri x bat dau cua table 	//	gotoxy(100, 12);//35 2 100 13 19,6 => tabx = 80 
#define taby 12  // vi tri y bat dau cua table
#define tabxCB 55

#define tabs 83 // table box
#define tabw 23 // table hight

#define ColorBLACK			0
#define ColorDARKBLUE		1
#define ColorDARKCYAN		3
#define ColorCDARKRED		4
#define ColorPURPLE			5
#define ColorDARKYELLOW		6
#define ColorDARKWHITE		7
#define ColorGRAY			8
#define ColorBLUE			9
#define ColorGREEN		 	10
#define ColorCYAN			11
#define ColorRED			12
#define ColorPINK			13
#define ColorYELLOW			14
#define ColorWHITE			255







using namespace std;


//=====================================================================================================================================
//===============================                 CAU TRUC DANH SACH VE      ==========================================================
//=====================================================================================================================================



struct ListVe{
	int n;

	string *ve;

};
void initListVe(ListVe &dsVe, int soCho){
	dsVe.n = 0;
	dsVe.ve = new string[soCho];
	for(int i = 0; i < soCho; i++ )
	{
//		strcpy(dsVe.ve[i], "");
		dsVe.ve[i] = "";
		//cout<<i<<"-"<<dsVe.ve[i]<<"-"<<dsVe.ve[i].length()<<endl;
//		strcpy(dsVe.ve[i].cmnd, "");
	}
}

bool InsertVe(ListVe &list, int soGhe, string cmnd)
{
	
	if ((list.ve[soGhe-1].length()) > 0)
		return false;
	else
	{
		
		list.ve[soGhe-1] = cmnd;
		list.n++;
		return true;
	}
}
bool DeleteVe(ListVe &list, int soGhe)
{
	
	if ((list.ve[soGhe-1].length()) > 0){
		list.ve[soGhe-1] = "";
		list.n--;
		return true;
	}else{
		return false;
	}
}

//=====================================================================================================================================
//===============================                 CAU TRUC THOI GIAN         ==========================================================
//=====================================================================================================================================



struct ThoiGian{
	int gio, phut, ngay, thang, nam;
};


bool Check_Date(int nam, int thang, int ngay)
{
	int Thang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ( (nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		Thang[1] = 29;
	}
	if (thang >= 1 && thang <= 12)
	{
		if (ngay >= 1 && ngay <= Thang[thang - 1])
		{
			return true;	
		}
	}
	return false;
}

bool Check_ThoiGian_ChuyenBay(ThoiGian tg)
{
	int Thang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (!Check_Date(tg.nam, tg.thang, tg.ngay)) return false;

	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ThoiGian dtNow;
	dtNow.nam = 1900 + ltm->tm_year;
	dtNow.thang = 1 + ltm->tm_mon;
	dtNow.ngay = ltm->tm_mday;
	dtNow.gio = ltm->tm_hour;
	dtNow.phut = ltm->tm_min;

	if (tg.nam < dtNow.nam) return false;
	if ((tg.nam == dtNow.nam) && (tg.thang < dtNow.thang))  return false;
	if ((tg.nam % 400 == 0) || (tg.nam % 4 == 0 && tg.nam % 100 != 0))
		Thang[1] = 29;
	if (tg.nam == dtNow.nam && tg.thang == dtNow.thang && tg.ngay < dtNow.ngay)return false;
	if (tg.nam == dtNow.nam && tg.thang == dtNow.thang && tg.ngay == dtNow.ngay && tg.gio < dtNow.gio)return false;
	if (tg.nam == dtNow.nam && tg.thang == dtNow.thang && tg.ngay == dtNow.ngay && tg.gio == dtNow.gio && tg.phut <= dtNow.phut)return false;





	return true;
}












bool Check_nam(int nam){
	
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ThoiGian dtNow;
	dtNow.nam = 1900 + ltm->tm_year;
	if(nam < dtNow.nam) return false;
	
	return true;
	
	
}
bool Check_thang(int thang,int nam){
	
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ThoiGian dtNow;
	dtNow.nam = 1900 + ltm->tm_year;
	dtNow.thang = 1 + ltm->tm_mon;
	if(thang < dtNow.thang &&  nam == dtNow.nam) return false;
	
	return true;
	
	
}
bool Check_Ngay(int ngay,int thang,int nam){
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ThoiGian dtNow;
	dtNow.nam = 1900 + ltm->tm_year;
	dtNow.thang = 1 + ltm->tm_mon;
	dtNow.ngay =  ltm->tm_mday;
	if(ngay < dtNow.ngay && thang == dtNow.thang &&  nam == dtNow.nam) return false;
	
	return true;
	
}

bool Check_Gio(int gio,int ngay,int thang,int nam){
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ThoiGian dtNow;
	dtNow.nam = 1900 + ltm->tm_year;
	dtNow.thang = 1 + ltm->tm_mon;
	dtNow.ngay =  ltm->tm_mday;
	dtNow.gio =  1 + ltm->tm_hour;
	if(gio < dtNow.gio && ngay == dtNow.ngay && thang == dtNow.thang &&  nam == dtNow.nam) return false;
	
	return true;
	
}


//=====================================================================================================================================
//===============================                 CAU TRUC CHUYEN BAY        ==========================================================
//=====================================================================================================================================




struct ChuyenBay{
	char maCB[16];
	ThoiGian tgKhoiHanh;
	char sanBayDen[150];
	int trangThai;
	char soHieuMB[16];
	ListVe dsVe;
		 
};
struct Node_CB{
	ChuyenBay cb;
	Node_CB *pNext;
};
struct SingleList_CB
{
	Node_CB *pHead;
	Node_CB *pTail;
};

Node_CB *SearchCB(SingleList_CB lcb, char maCB[])
{
	Node_CB *pNode = lcb.pHead;
	while (pNode != NULL)
	{
		if (strcmp(pNode->cb.maCB, maCB) == 0)
			return pNode;
		pNode=pNode->pNext;
	}
	return NULL;
}



void Init_CB(SingleList_CB &listCB)
{
	listCB.pHead = listCB.pTail = NULL;
}

int Dem(SingleList_CB lcb, char soHieu[])
{
	int dem = 0;
	Node_CB *pNode = lcb.pHead;
	while (pNode != NULL)
	{
		if (strcmp(pNode->cb.soHieuMB, soHieu) == 0)
			if (pNode->cb.trangThai == 3)
				dem++;
		pNode = pNode->pNext;
	}
	return dem;
}


int Check_MaCB(SingleList_CB listCB, char macb[])
{
	Node_CB *pTmp = listCB.pHead;
	if (pTmp == NULL)
		return -1;
	else
	{
		for (; pTmp != NULL; pTmp=pTmp->pNext)
		{
			if (strcmp(pTmp->cb.maCB, macb) == 0)
				return 1;
		}
	}
	return -1;
}

int Check_NoiDen(SingleList_CB lcb, char noiden[])
{
	Node_CB *pTmp = lcb.pHead;
	if (pTmp == NULL) return -1;
	else
	{
		for (; pTmp != NULL; pTmp=pTmp->pNext)
		{
			if (strcmp(pTmp->cb.sanBayDen, noiden) == 0)
				return 1;
		}
	}
	return -1;
}


int CheckHKTrongCB(ListVe lv, int socho, char cmnd[])
{
	for(int i = 0; i < socho; i++)
	{
		if (lv.ve[i] == cmnd)
			return 1;
	}
	return -1;
}
bool CheckHKTrongCBHayKhong(ListVe lv, int socho)
{
	for(int i = 0; i < socho; i++)
	{
		if (lv.ve[i] != "")
			return true;
	}
	return false;
}




Node_CB *CreateNode_CB(ChuyenBay cb_moi)
{
	Node_CB *pNode = new Node_CB;
	if(pNode != NULL)
	{
		pNode->cb = cb_moi;
		pNode->pNext = NULL;
	}
	else
		cout<<"Tao Node_CB that bai";
	return pNode;
}

void InsertLast_CB(SingleList_CB &listCB, ChuyenBay cb_moi)
{
	Node_CB *pNode = CreateNode_CB(cb_moi);
	if (listCB.pHead == NULL)
	{
		listCB.pHead = listCB.pTail = pNode;
	}
	else
	{
		listCB.pTail->pNext = pNode;
		listCB.pTail = pNode;
	}
}

Node_CB * TimKiem_CB(SingleList_CB listCB, char maCB[])
{
	for (Node_CB *pNode = listCB.pHead; pNode != NULL; pNode = pNode->pNext)
	{
		if (strcmp(pNode->cb.maCB, maCB) == 0)
			return pNode;
	}
	return NULL;
}

bool Delete_CB_Theo_Ma(SingleList_CB &listCB, char ma[])
{
	Node_CB *pDel = listCB.pHead;
	if (pDel == NULL)
		return false;
	else
	{
		Node_CB *pPre = NULL;
		while (pDel != NULL)
		{
			if (strcmp(pDel->cb.maCB, ma) == 0)
				break;
			pPre = pDel;
			pDel = pDel->pNext;
		}
		if (pDel == NULL)
		{
			return false;
		}
		else
		{
			if (pDel == listCB.pHead)
			{
				listCB.pHead = listCB.pHead->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
				return true;
			}
			else if (pDel->pNext == NULL)
			{
				listCB.pTail = pPre;
				pPre->pNext = NULL;
				delete pDel;
				pDel = NULL;
				return true;
			}
			else
			{
				pPre->pNext = pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
				return true;
			}
		}
	}
	
}


// TEST: in thu Danh sach CB
void PrintList_CB(SingleList_CB listCB)
{
	Node_CB *pTmp = listCB.pHead;
	if(pTmp == NULL)
	{
		cout<<"Danh sach rong!";
		return;
	}
	for (pTmp; pTmp != NULL; pTmp = pTmp->pNext)
	{
		ChuyenBay cb = pTmp->cb;
		cout<<cb.soHieuMB<<"\t"
			<<cb.maCB<<"\t"
			<<cb.tgKhoiHanh.ngay<<"/"<<cb.tgKhoiHanh.thang<<"/"<<cb.tgKhoiHanh.nam<<"  "<<cb.tgKhoiHanh.gio<<":"<<cb.tgKhoiHanh.phut<<"\t"
			<<cb.sanBayDen<<"\t"
			<<cb.trangThai<<endl;
		cout<<" --- DANH SACH VE ---"<<endl;
		for (int i = 0; i < cb.dsVe.n; i++)
		{
			if (cb.dsVe.ve[i] != "")
				cout<<i+1<<"-"<<cb.dsVe.ve[i]<<endl;
		}
	}
}

//kiem tra trung ngay Note 
bool Check_trungDate(SingleList_CB lcb,ThoiGian time) {
	Node_CB *pTmp = lcb.pHead;
	if (pTmp == NULL) {
		return true;
	}
	else {
		while (pTmp != NULL) {
				if (pTmp->cb.tgKhoiHanh.nam == time.nam) {
					if (pTmp->cb.tgKhoiHanh.thang == time.thang) {
						if (pTmp->cb.tgKhoiHanh.ngay == time.ngay) {
							if (pTmp->cb.tgKhoiHanh.gio == time.gio) {
								return false;
							}
						}
					}
				}
				pTmp = pTmp->pNext;
			}
		}
	return true;
}
//kiem tra danh sach ve full chua Note
bool Them_Ve_Duoc(ChuyenBay cb,int socho) {
	if (0 <= cb.dsVe.n && cb.dsVe.n <= socho)
	{
		return true;
	}
	return false;
}
//kiem tra vi tri ghe trong ko
bool Check_ViTri_Ghe(SingleList_CB lcb, int vitri) {
	Node_CB *pTmp = lcb.pHead;
	if (pTmp->cb.dsVe.ve[vitri] != "") {
		return true;
	}
	else return false;
}

bool CheckTrungThoiGianBay(SingleList_CB &listCB,char sohieu[],int gioBay,int Ngaybay,int Thangbay,int Nambay){
		
		for (Node_CB *pNode = listCB.pHead; pNode != NULL; pNode=pNode->pNext)
		{
			if(stricmp(pNode->cb.soHieuMB, sohieu) == 0)
			if(pNode->cb.tgKhoiHanh.ngay == Ngaybay && pNode->cb.tgKhoiHanh.thang == Thangbay && pNode->cb.tgKhoiHanh.nam == Nambay ){
					if (pNode->cb.tgKhoiHanh.gio == gioBay || pNode->cb.tgKhoiHanh.gio == gioBay+1 || pNode->cb.tgKhoiHanh.gio == gioBay+2 || pNode->cb.tgKhoiHanh.gio == gioBay+3)
					{
						return false;
					}
				
			}
			
		}
		return true;		
}









//=====================================================================================================================================
//===============================                 CAU TRUC MAY BAY           ==========================================================
//=====================================================================================================================================
struct MayBay{
	char soHieuMB[16];
	char loaiMB[41];
	int soCho;
};

struct ListMayBay{
	int soluong;
	MayBay *maybay[MAXMB]; 
};


int Empty_MB(ListMayBay dsMB)
{
	return dsMB.soluong == 0;
}
bool Full_MB(ListMayBay dsMB)
{
	if(dsMB.soluong == MAXMB)
	return true;
 	else
 	return false;
}


int getsocho(ListMayBay lmb, char soHieu[])
{
	for (int i = 0; i < lmb.soluong; i++)
	{
		if (strcmp(lmb.maybay[i]->soHieuMB, soHieu) == 0)
			return lmb.maybay[i]->soCho;
	}
	return -1;
}

int Insert_MB(ListMayBay &listMB, MayBay mb)
{
	int empty = Empty_MB(listMB);
	int full = Full_MB(listMB);
	if (empty == 1)
	{
		listMB.maybay[0] = new MayBay;
 		strcpy(listMB.maybay[0]->soHieuMB, mb.soHieuMB);
		listMB.maybay[0]->soCho = mb.soCho;
		strcpy(listMB.maybay[0]->loaiMB , mb.loaiMB);
		listMB.soluong = 1;
		return 1;
	}
	else if (full)
	{
		return -1;
	}
		
	else
	{
		listMB.maybay[listMB.soluong] = new MayBay;
		strcpy(listMB.maybay[listMB.soluong]->soHieuMB, mb.soHieuMB);
		listMB.maybay[listMB.soluong]->soCho = mb.soCho;
		strcpy(listMB.maybay[listMB.soluong]->loaiMB , mb.loaiMB);
		listMB.soluong++;
		return 1;
	}
}


int CheckSoHieu_MB(ListMayBay listMB, char sohieu[])
{
	if (Empty_MB(listMB))
		return -1;
	else
	{
		for (int i = 0; i < listMB.soluong; i++)
		{
			if (stricmp(listMB.maybay[i]->soHieuMB, sohieu) == 0)
				return i;
		}
		return -1;
	}
}



void Delete_MB(ListMayBay &listMB, char sohieu[])
{
	for (int i = 0; i < listMB.soluong; i++)
	{
		if (strcmp(listMB.maybay[i]->soHieuMB, sohieu) == 0)
		{
			MayBay* temp = listMB.maybay[i];
			int j = i+1;
			for( j ; j < listMB.soluong; j++){
				listMB.maybay[i] = listMB.maybay[j];
				i = j;
			}
			delete temp;
			listMB.maybay[j] = NULL;
			listMB.soluong--;
			cout<<"Da xoa\n";
			break;
		}
		
	}
	
}



//=====================================================================================================================================
//===============================                 XU LY NHAP                 ==========================================================
//=====================================================================================================================================

int check_Chuoi_Char(char ma[])
{
	for(int i = 0; i < strlen(ma); i++){
//		gotoxy(1,1); cout<<ma[i]<<endl;
//		system("pause");
		if (!isdigit(ma[i]))
			return -1;
	}
	return 1;
} 
void XoaKiTu(char s[], int vitrixoa)
{
	int n = strlen(s);
	for (int i = vitrixoa + 1; i < n; i++)
		s[i-1] = s[i];
	s[n-1] = '\0';
}
char *fix_Ma(char *ma)
{
	if( strcmp(ma, "\0") == 0)
		return ma;
	int dai = strlen(ma);
	int dem = 0;
	for(int i = 0; i < dai; i++)
	{
		if (ma[i] == ' ')
			dem++;
	}
	if (dem == dai)
	{
		while (true)
		{
			if (ma[0] == ' ')
				XoaKiTu(ma, 0);
			else if (ma[strlen(ma)-1] == ' ')
				XoaKiTu(ma, strlen(ma)-1);
			else
				break;
		}
		return ma;
	}
		
	while (true)
	{
		if (ma[0] == ' ')
			XoaKiTu(ma, 0);
		else if (ma[strlen(ma)-1] == ' ')
			XoaKiTu(ma, strlen(ma)-1);
		else
			break;
	}
	// Xoa khoang tang o giua
	for (int i = 0; i < strlen(ma) - 1; i++)
	{
		if ((ma[i] == ' ' && ma[i+1] == ' ') || (ma[i] == ' ' && ma[i+1] != ' '))
		{
			XoaKiTu(ma, i);
			i--;
		}
	}
	if (strcmp(ma, "") != 0)
	{
		// Chuyen chu thuong thanh chu hoa
		for (int i = 0; i < strlen(ma); i++)
		{
			if (ma[i] >= 'a' && ma[i] <= 'z')
				ma[i] -= 32;
		}
	}
	return ma;
}


char *tach_Ten(char str[])
{
	char *ten = new char[100];
	
	for (int i = strlen(str)-1; i >= 0; i--)
		if (str[i] == ' ')
		{
			int k = 0;
			for (int j = i + 1; j < strlen(str); j++)
			{
				ten[k++] = str[j];
			}
			ten[k]='\0';
			break;
		}
	return ten;
}

char *tach_ho_dem(char str[])
{
	char *hodem = new char[100];

	for (int i = strlen(str)-1; i >= 0; i--)
		if (str[i] == ' ')
		{
			int k = 0;
			for (int j = 0; j < i; j++)
			{
				hodem[k++] = str[j];
			}
			hodem[k]='\0';
			break;
		}
	return hodem;
}
char *fix_HoTen(char *hoten)
{
	if( strcmp(hoten, "\0") == 0)
		return hoten;
		
	int dai = strlen(hoten);
	int dem = 0;
	for(int i = 0; i < dai; i++)
	{
		if (hoten[i] == ' ')
			dem++;
	}
	if (dem == dai)
	{
		while (true)
		{
			if (hoten[0] == ' ')
				XoaKiTu(hoten, 0);
			else if (hoten[strlen(hoten)-1] == ' ')
				XoaKiTu(hoten, strlen(hoten)-1);
			else
				break;
		}
		return hoten;
	}
	// Xoa khoang trang dau va cuoi
	while (true)
	{
		if (hoten[0] == ' ')
			XoaKiTu(hoten, 0);
		else if (hoten[strlen(hoten)-1] == ' ')
			XoaKiTu(hoten, strlen(hoten)-1);
		else
			break;
	}
	// Xoa khoang tang o giua
	for (int i = 0; i < strlen(hoten) - 1; i++)
	{
		if (hoten[i] == ' ' && hoten[i+1] == ' ')
		{
			XoaKiTu(hoten, i);
			i--;
		}
	}
	// Chuyen Hoa thanh thuong
	for(int i = 0; i < strlen(hoten); i++)
		if(hoten[i] >= 'A' && hoten[i] <= 'Z') hoten[i] += 32;
	
	hoten[0] = hoten[0] - 32; // In hoa Ki tu dau tien
	
	for(int i = 1;i < strlen(hoten); i++) // In hoa chu cai dau tien sau moi khoang trang
	{
		if(hoten[i] == ' ')
		{
			if(hoten[i+1] >= 'a' && hoten[i+1] <= 'z')
			{
				hoten[i+1] -= 32;
				i = i+1;
			}
		}
	}
	return hoten;
}
char *fix_Ten(char *ma)
{
	if( strcmp(ma, "\0") == 0)
		return ma;
	int dai = strlen(ma);
	int dem = 0;
	for(int i = 0; i < dai; i++)
	{
		if (ma[i] == ' ')
			dem++;
	}
	if (dem == dai)
	{
		while (true)
		{
			if (ma[0] == ' ')
				XoaKiTu(ma, 0);
			else if (ma[strlen(ma)-1] == ' ')
				XoaKiTu(ma, strlen(ma)-1);
			else
				break;
		}
		return ma;
	}
		
	while (true)
	{
		if (ma[0] == ' ')
			XoaKiTu(ma, 0);
		else if (ma[strlen(ma)-1] == ' ')
			XoaKiTu(ma, strlen(ma)-1);
		else
			break;
	}
	// Xoa khoang tang o giua
	for (int i = 0; i < strlen(ma) -1; i++)
	{
		if (ma[i] == ' ' && ma[i+1] == ' ') 
		{
//			|| (ma[i] == ' ' && ma[i+1] != ' ')
			XoaKiTu(ma, i);
			i--;
		}
	}

	// Chuyen Hoa thanh thuong
	for(int i = 0; i < strlen(ma); i++)
		if(ma[i] >= 'A' && ma[i] <= 'Z') ma[i] += 32;
		
	
	ma[0] = ma[0] - 32; // In hoa Ki tu dau tien
	for (int i = 0; i < strlen(ma) -1; i++)
	{
		if (ma[i] == ' ' && ma[i+1] != ' ') 
		{
//			|| (ma[i] == ' ' && ma[i+1] != ' ')
			ma[i+1] = ma[i+1] -32;
		}
	}
	
	
	
	return ma;
}

char *fix_GioiTinh(char *phai)
{
	if (strcmp(phai, "\0") == 0)
		return phai;
		
	int dai = strlen(phai);
	int dem = 0;
	for (int i = 0; i < dai; i++)
	{
		if (phai[i] == ' ')
			dem++;
	}
	if (dem == dai)
	{
		while (true)
		{
			if (phai[0] == ' ')
				XoaKiTu(phai, 0);
			else if (phai[strlen(phai)-1] == ' ')
				XoaKiTu(phai, strlen(phai)-1);
			else
				break;
		}
		return phai;
	}
	// Xoa khoang trang dau va cuoi
	while (true)
	{
		if (phai[0] == ' ')
			XoaKiTu(phai, 0);
		else if (phai[strlen(phai)-1] == ' ')
			XoaKiTu(phai, strlen(phai)-1);
		else
			break;
	}
	
	// Chuyen Hoa thanh thuong
	for(int i = 0; i < strlen(phai); i++)
		if(phai[i] >= 'A' && phai[i] <= 'Z') phai[i] += 32;
	return phai;
}


//=====================================================================================================================================
//===============================                 XU LY FILE                ==========================================================
//=====================================================================================================================================






void LuuFileHanhKhach(AVLTree tree_hk, ofstream &fileout)
{
	if (tree_hk != NULL)
	{
		fileout<<tree_hk->hanhkhach.cmnd<< ","<<tree_hk->hanhkhach.ho<<" "<<tree_hk->hanhkhach.ten<<","<<tree_hk->hanhkhach.phai;
		LuuFileHanhKhach(tree_hk->pLeft, fileout);
		LuuFileHanhKhach(tree_hk->pRight, fileout);
	}
}
void LuuFileHKKoDeQuy(AVLTree tree_hk)
{
	ofstream fileout;
	fileout.open("hanhkhach.txt", ios::out);
	if (fileout.fail())
	{
		cout<<"Loi mo file hanh khach";
		return;
	}
	const int STACKSIZE = 10000;
	AVLTree Stack[STACKSIZE];
	AVLTree p = tree_hk;
	int sp = -1; //Khai bao Stack rong
	do
	{
		while(p!=NULL)
		{
			Stack[++sp] = p;
			p = p->pLeft;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			fileout<<p->hanhkhach.cmnd<<","<<p->hanhkhach.ho<<" "<<p->hanhkhach.ten<<","<<p->hanhkhach.phai<<endl;
			p = p->pRight;
		}
		else break;
	}while(1);
}

void DocFileHanhKhach(AVLTree &tree_hk)
{
	ifstream filein;
	filein.open("hanhkhach.txt", ios::in);
	HanhKhach hk;
	string tmp; // lay ky tu xuong dong 
	do{
		string cmnd, hoten;
	
		getline(filein, cmnd, ',');
		if(cmnd != ""){
			strcpy(hk.cmnd, cmnd.c_str());
			
			getline(filein, hoten, ',');
			char ho[100], ten[100], hotenc[200];
			strcpy(hotenc, hoten.c_str());
			
			strcpy(hk.ho, tach_ho_dem(hotenc));
		
			strcpy(hk.ten, tach_Ten(hotenc));
		
			filein>>hk.phai;
		
			getline(filein, tmp);
			InsertHKToTree(tree_hk, hk);
		}
	}while(!filein.eof());
	filein.close();
}






void LuuFileChuyenBay(SingleList_CB listCB, ListMayBay lmb)
{
	ofstream fileout;
	fileout.open("chuyenbay.txt", ios::out);
	Node_CB *pTmp = listCB.pHead;
	for ( ; pTmp != NULL; pTmp=pTmp->pNext)	{
		ChuyenBay cb;
		cb = pTmp->cb;
		fileout << cb.soHieuMB << endl;
		fileout << cb.maCB << "," 
				<< cb.tgKhoiHanh.ngay << "/" 
				<< cb.tgKhoiHanh.thang << "/" 
				<< cb.tgKhoiHanh.nam << ","
				<< cb.tgKhoiHanh.gio << ":"
				<< cb.tgKhoiHanh.phut << endl;
		fileout << cb.sanBayDen <<endl;
		fileout << cb.trangThai <<endl;
		int socho = getsocho(lmb, cb.soHieuMB);
		for(int vitri = 0; vitri < socho; vitri++){
			if((cb.dsVe.ve[vitri].length() > 0))
			{
				gotoxy(1,1); cout << cb.dsVe.ve[vitri].length();
				fileout << vitri+1 << "-" << cb.dsVe.ve[vitri] << endl;
			}
		}
		fileout << endl << endl;
	}

	fileout.close();
}


void LuuFileMayBay(ListMayBay listMB, ofstream &fileout)
{
	fileout << listMB.soluong<<endl;
	for (int i = 0; i < listMB.soluong; i++)
	{
		fileout << listMB.maybay[i]->soHieuMB << ","<<listMB.maybay[i]->loaiMB << ","<<listMB.maybay[i]->soCho<<endl;
	}
	
	fileout.close();
}



void DocFileMayBay(ListMayBay &listmb)
{
	ifstream filein;
	filein.open("maybay.txt", ios::in);
	int n; // get so luong may bay
	listmb.soluong = 0;
	string tmp;
	
	filein>>n;
	
	getline(filein,tmp);
	for (int i = 0; i < n; i++)
	{

		MayBay mb;
		getline(filein, tmp, ',');
		strcpy(mb.soHieuMB, tmp.c_str());
		
		getline(filein, tmp, ',');
		strcpy(mb.loaiMB, tmp.c_str());
		
		
		filein >> mb.soCho;
		getline(filein, tmp);
		
		Insert_MB(listmb, mb);
	}
	filein.close();
}

bool Check_ThoiGian_ChuyenBay(ThoiGian tg);
void InsertLast_CB(SingleList_CB &lcb, ChuyenBay cb);
string *splitToTwoString(const string str, char splitchar);
void DocFileChuyenBay(SingleList_CB &lcb, ListMayBay lmb)
{
	ifstream filein;
	filein.open("chuyenbay.txt", ios::in);
	string tmp; 
	do
	{
		ChuyenBay cb;
		
		getline(filein, tmp);
		if (tmp != ""){
			strcpy(cb.soHieuMB, tmp.c_str());
			
			getline(filein, tmp, ',');
			strcpy(cb.maCB, tmp.c_str());
//			cout<<cb.maCB<<endl;
			getline(filein, tmp, '/');
			cb.tgKhoiHanh.ngay = atoi(tmp.c_str());
			
			getline(filein, tmp, '/');
			cb.tgKhoiHanh.thang = atoi(tmp.c_str());
			
			getline(filein, tmp, ',');
			cb.tgKhoiHanh.nam = atoi(tmp.c_str());
			
			getline(filein, tmp, ':');
			cb.tgKhoiHanh.gio = atoi(tmp.c_str());
			
			getline(filein, tmp);
			cb.tgKhoiHanh.phut = atoi(tmp.c_str());
			
			
			getline(filein, tmp);
			strcpy(cb.sanBayDen, tmp.c_str());

			getline(filein, tmp);
			cb.trangThai = atoi(tmp.c_str());
			if (Check_ThoiGian_ChuyenBay(cb.tgKhoiHanh) == false)
				cb.trangThai = 3;
				
			initListVe(cb.dsVe, getsocho(lmb, cb.soHieuMB));

			string tmp1 = "";
			getline(filein, tmp1);
			
			while(tmp1 != "")
			{
				string *arrVe = splitToTwoString(tmp1, '-');
				string ghe = arrVe[0];
				string cmnd = arrVe[1];

				
				InsertVe(cb.dsVe, atoi(ghe.c_str()), cmnd);
				getline(filein, tmp1);
				
			}
			
			InsertLast_CB(lcb, cb);
			tmp = "";
		}
		
	}while (!filein.eof());
}

string* splitToTwoString(const string str, char splitchar){
	int pos = 0;
	string* arr = new string[2];
	arr[0] = "";
	arr[1] = "";
	for(pos; pos < str.length();pos ++){
		if(str.at(pos) == splitchar){
			arr[0] = str.substr(0,pos); // 12-
			arr[1] = str.substr(pos+1, str.length()-pos);
		}
	}
	return arr;
}




void Xuat_MB(ListMayBay listMB)
{
	cout<<"So luong: "<<listMB.soluong<<endl;
	for (int i = 0; i < listMB.soluong; i++)
	{
		cout<<listMB.maybay[i]->soHieuMB<<"\t"<<listMB.maybay[i]->loaiMB<<"\t"<<listMB.maybay[i]->soCho<<endl;
	}
}





//=====================================================================================================================================
//===============================                 XU LY DO HOA                =========================================================
//=====================================================================================================================================





void ButtonXoa(int color)
{
	gotoxy(35, 31); SetBGColor(color); 						cout << "      ";
	gotoxy(35, 32); SetBGColor(color); 	SetColor(ColorBLACK);	cout << "  F2  ";
	gotoxy(35, 33); SetBGColor(color); 						cout << "      ";
	gotoxy(35, 35); SetBGColor(ColorBLACK); SetColor(ColorWHITE); 	cout << "  XOA ";
}

void ButtonSua(int color)
{
	gotoxy(52, 31); SetBGColor(color); 						cout << "      ";
	gotoxy(52, 32); SetBGColor(color); SetColor(ColorBLACK);	cout << "  F3  ";
	gotoxy(52, 33); SetBGColor(color); 						cout << "      ";
	gotoxy(52, 35); SetBGColor(ColorBLACK); SetColor(ColorWHITE);	cout << "  SUA ";
}


void Box_NhapMayBay()
{
	SetColor(15);
//	gotoxy(boxx,boxy);cout
	gotoxy(boxx, boxy); cout << char(201);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	
	gotoxy(boxx, boxy + 1); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 1); cout << char(186);
	
	gotoxy(boxx, boxy + 2); cout << char(186)<< " Nhap vao so hieu may bay: "; // boxx+27       boxx + 61
	gotoxy(boxx + boxs + 1, boxy + 2); cout << char(186);
	
	gotoxy(boxx, boxy + 3); cout << char(186) ;
	gotoxy(boxx + boxs + 1, boxy + 3); cout << char(186);
	gotoxy(boxx, boxy + 4); cout << char(186)<< "    Nhap vao loai may bay: ";
	gotoxy(boxx + boxs + 1, boxy + 4); cout << char(186);
	gotoxy(boxx, boxy + 5); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 5); cout << char(186);
	gotoxy(boxx, boxy + 6); cout << char(186)<< "          Nhap vao so cho: ";
	gotoxy(boxx + boxs + 1, boxy + 6); cout << char(186);
	gotoxy(boxx, boxy + 7); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 7); cout << char(186);
	gotoxy(boxx, boxy + 8); cout << char(200);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(188); 
}

void Box_SuaMayBay()
{
	SetColor(15);
	VeHCN( boxx-1-29,boxy-2,90, 2,15);
	gotoxy(boxx , boxy - 1); cout<<"THONG TIN";
	gotoxy(boxx + 35, boxy - 1); cout<<"DANG SUA";
	
	VeHCN( boxx-1-29,boxy-2,90, 10,15);
	
	VeHCN( boxx+30,boxy-2,30, 10,15);
	gotoxy(boxx-30+2, boxy + 2); cout << " Nhap vao so hieu may bay: "; 

	
	gotoxy(boxx-30+2, boxy + 4); cout << "    Nhap vao loai may bay: ";


	gotoxy(boxx-30+2, boxy + 6); cout << "          Nhap vao so cho: ";

}
void Box_SuaChuyenBayBay()
{
	
	

	VeHCN( boxx-20-3-2-1+10,boxy-6+4,85, 16,15);
//	VeHCN( boxx-20-3-2-1+28,boxy-6+4,85-28, 16,15);
	VeHCN( boxx-20-3-2-1+28+28+10,boxy-6+4,85-28-28, 16,15);
	gotoxy(boxx-20-5+10, boxy - 6+5); cout << " Nhap vao so hieu may bay: ";
	gotoxy(boxx-20-5+10, boxy - 4+5); cout << "       Nhap ma chuyen bay: ";
	gotoxy(boxx-20-5+10, boxy - 2+5); cout << "                      Nam: ";
	gotoxy(boxx-20-5+10, boxy+5); 	cout << "                    Thang: ";
	gotoxy(boxx-20-5+10, boxy + 2+5); cout << "                     Ngay: ";
	gotoxy(boxx-20-5+10, boxy + 4+5); cout << "                      Gio: ";
	gotoxy(boxx-20-5+10, boxy + 6+5); cout << "                     Phut: ";
	gotoxy(boxx-20-5+10, boxy + 8+5); cout << "              San bay den: ";
	
	

}


void Box_NhapHanhKhach()
{
	
	gotoxy(75+15+3,15-2);SetColor(5);cout<<"<";  
	gotoxy(75+15+3+3,15-2);SetColor(12);cout<<"NHAP HANH KHACH";
	gotoxy(75+15+3+18+3,15-2);SetColor(5);cout<<">";
	VeHCN(75,15,55,13,1);
	gotoxy(80, 17);cout <<"Nhap CMND        : ";
	VeHCN(99,16,30,2,255);
	
	gotoxy(80, 20);cout<< "Nhap Ho          : ";
	VeHCN(99,19,30,2,255);

	gotoxy(80, 23);cout <<"Nhap Ten         : ";
	VeHCN(99,22,30,2,255);

	gotoxy(80,26); cout <<"Nhap phai(nam/nu): ";
	VeHCN(99,25,30,2,255);

}

void Box_DS_HK_Trong_CB()
{
//	resizeConsole(800,600);
	XoaManHinhTrungTam();
	
	VeHCN(6,24,40-7-5,5,10);
	SetColor(255);
	gotoxy(4, 22);
	cout << "MA CHUYEN BAY: "; // 80,2
	gotoxy(8,25);
	cout << "Ngay gio thoi hanh: "; // 49,3
	//VeHCN()
	gotoxy(10,26); cout<<"/";
	gotoxy(13,26); cout<<"/";
	gotoxy(13,27); cout<<":";
	gotoxy(8,28);
	cout << "Noi den:"; // 77,3
	
	gotoxy(tabx, taby);
	cout << char(218);
	//-------- dong dau
	for(int i = 1; i < tabs ; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	
	//cot dau
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx, taby + i);
		cout << char(179);
	}
	//cot cuoi
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + tabs, taby + i);
		cout << char(179) ;
	}
	
	gotoxy(tabx, taby + tabw);
	cout << char(192);
	//dong cuoi
	for(int i = 1; i < tabs + 1; i++)
	{
		gotoxy(tabx + i, taby + tabw);
		cout << char(196);
	}
	gotoxy(tabx + tabs , taby + tabw);
	cout << char(217);

	// STT
	gotoxy(tabx + 3, taby + 1); cout << "STT";
	gotoxy(tabx + 8, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 8, taby + i); cout << char(179); // cot stt
	}
	
	gotoxy(tabx, taby + 2);
	cout << char(195);
	// dong hai
	for(int i = 1; i < tabs ; i++)
	{
		gotoxy(tabx + i, taby + 2);
		cout << char(196);
	}
	gotoxy(tabx + 8, taby + 2); cout << char(197);
	gotoxy(tabx + tabs , taby + 2); cout << char(180);
	gotoxy(tabx + 8, taby + tabw); cout << char(193);

	// SO HIEU
	gotoxy(tabx + 12, taby + 1); cout << "SO VE";
	gotoxy(tabx + 20, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 20, taby + i); cout << char(179);
	}
	gotoxy(tabx + 20, taby + 2); cout << char(197);
	gotoxy(tabx + 20, taby + tabw); cout << char(193);

	// LOAI
	gotoxy(tabx + 26, taby + 1); cout << "CMND";
	gotoxy(tabx + 38, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 38, taby + i); cout << char(179);
	}
	gotoxy(tabx + 38, taby + 2); cout << char(197);
	gotoxy(tabx + 38, taby + tabw); cout << char(193);

	// SO CHO
	gotoxy(tabx + 50, taby + 1); cout << "HO TEN";
	gotoxy(tabx + 70, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 70, taby + i); cout << char(179);
	}
	gotoxy(tabx + 70, taby + 2); cout << char(197);
	gotoxy(tabx + 70, taby + tabw); cout << char(193);
	
	// PHAI
	gotoxy(tabx + 75, taby + 1); cout << "PHAI";
}








void Box_DS_Ve_Trong_Trong_CB()
{
	/////
//	resizeConsole(800,600);
//	gotoxy(35, 2);
//	cout << "DANH SACH VE TRONG CUA CHUYEN BAY";
//	gotoxy(42,3); cout<<"Ma: "; // 46,3
	SetColor(255);
	gotoxy(tabx+30, taby);
	cout << char(218);
	//-------- dong dau
	for(int i = 1; i < tabs - 53 ; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	
	//cot dau
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx+30, taby + i);
		cout << char(179);
	}
	//cot cuoi
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + tabs - 23, taby + i);
		cout << char(179) ;
	}
	
	gotoxy(tabx+30, taby + tabw);
	cout << char(192);
//	//dong cuoi
	for(int i = 1; i < tabs - 53; i++)
	{
		gotoxy(tabx + i + 30, taby + tabw);
		cout << char(196);
	}
	gotoxy(tabx + tabs - 23, taby + tabw);
	cout << char(217);

	// STT
	gotoxy(tabx + 40, taby + 1); cout << "VE TRONG";
	// dong hai
	for(int i = 1; i < tabs - 53 ; i++)
	{
		gotoxy(tabx + i + 30, taby + 2);
		cout << char(196);
	}
//	gotoxy(tabx + 10, taby + 2); cout << char(197);
	gotoxy(tabx + tabs - 23, taby + 2); cout << char(180);
	gotoxy(tabx + 30, taby + 2); cout << char(195);
//	gotoxy(tabx + 45, taby + tabw); cout << char(193);
//
//	// VE TRONG
//	gotoxy(tabx + 55, taby + 1); cout << "VE TRONG";

}
void BoxTrangThai(int color)
{
	VeHCN(150,12,15,6,ColorWHITE);
	gotoxy(151, 13); SetBGColor(color); SetColor(ColorPINK); cout <<  "  TRANG THAI ";
	gotoxy(151, 14); SetBGColor(color); SetColor(ColorRED);   cout << "0. Huy Chuyen";
	gotoxy(151, 15); SetBGColor(color); SetColor(ColorGREEN); cout << "1. Con Ve    ";
	gotoxy(151, 16); SetBGColor(color); SetColor(ColorPURPLE);cout << "2. Het Ve    ";
	gotoxy(151, 17); SetBGColor(color); SetColor(ColorBLUE);  cout << "3. Hoan Tat  ";
	SetBGColor(ColorBLACK); SetColor(ColorWHITE);
}
void BoxThoiGian(int color)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ThoiGian dtNow;
	dtNow.nam = 1900 + ltm->tm_year;
	dtNow.thang = 1 + ltm->tm_mon;
	dtNow.ngay = ltm->tm_mday;
	dtNow.gio = ltm->tm_hour;
	dtNow.phut = ltm->tm_min;
	VeHCN(145,12,20,6,ColorWHITE);
	gotoxy(146, 13); SetBGColor(color); SetColor(ColorPINK); cout <<  "  Thoi gian  ";
	gotoxy(146, 14); SetBGColor(color); SetColor(ColorGREEN);   cout << "Ngay : "<<dtNow.ngay<<"/"<<dtNow.thang<<"/"<<dtNow.nam;
	gotoxy(146, 15); SetBGColor(color); SetColor(ColorYELLOW); 	cout << "Gio  : "<<dtNow.gio<<":"<<dtNow.phut;

	SetBGColor(ColorBLACK); SetColor(ColorWHITE);
}

void Box_NhapChuyenBayBay()
{
	//system("cls");
	SetColor(15);
	
	//gotoxy(40,4); cout<<"--- THEM CHUYEN BAY ---";
	
	gotoxy(boxxCB+11, boxyCB - 8+6); cout << char(201);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	
	gotoxy(boxxCB+11, boxyCB - 7+6); cout << char(186);
	gotoxy(boxxCB+11 + boxs + 1, boxyCB +6- 7); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB - 6+6); cout << char(186)<< " Nhap vao so hieu may bay: ";
	gotoxy(boxxCB+11 + boxs + 1, boxyCB - 6+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB - 5+6); cout << char(186) ;
	gotoxy(boxxCB+11 + boxs + 1, boxyCB - 5+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB - 4+6); cout << char(186)<< "       Nhap ma chuyen bay: ";
	gotoxy(boxxCB+11 + boxs + 1, boxyCB - 4+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB - 3+6); cout << char(186);
	gotoxy(boxxCB+11 + boxs + 1, boxyCB - 3+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB - 2+6); cout << char(186)<< "                      Nam: ";
	gotoxy(boxxCB+11 + boxs + 1, boxyCB - 2+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB - 1+6); cout << char(186);
	gotoxy(boxxCB+11 + boxs + 1, boxyCB - 1+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB+6); 	cout << char(186)<< "                    Thang: ";
	gotoxy(boxxCB+11 + boxs + 1, boxyCB+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB + 1+6); cout << char(186);
	gotoxy(boxxCB+11 + boxs + 1, boxyCB + 1+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB + 2+6); cout << char(186)<< "                     Ngay: ";
	gotoxy(boxxCB+11 + boxs + 1, boxyCB + 2+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB + 3+6); cout << char(186);
	gotoxy(boxxCB+11 + boxs + 1, boxyCB + 3+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB + 4+6); cout << char(186)<< "                      Gio: ";
	gotoxy(boxxCB+11 + boxs + 1, boxyCB + 4+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB + 5+6); cout << char(186);
	gotoxy(boxxCB+11 + boxs + 1, boxyCB + 5+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB + 6+6); cout << char(186)<< "                     Phut: ";
	gotoxy(boxxCB+11 + boxs + 1, boxyCB + 6+6); cout << char(186);
	
	gotoxy(boxxCB+11, boxyCB + 7+6); cout << char(186);
	gotoxy(boxxCB+11 + boxs + 1, boxyCB +6+ 7); cout << char(186);
	
	gotoxy(boxxCB+11, boxy +6+ 8); cout << char(186)<< "              San bay den: ";
	gotoxy(boxxCB+11 + boxs + 1, boxy+6 + 8); cout << char(186);
	
	gotoxy(boxxCB+11, boxy+6 + 9); cout << char(186);
	gotoxy(boxxCB+11 + boxs + 1, boxy+6 + 9); cout << char(186);
	
	gotoxy(boxxCB+11, boxy+6 + 10); cout << char(200);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(188); 
	BoxThoiGian(0);
}



void Box_DS_CB_Khoi_Ngay_Theo_Ngay()
{
	/////
//	resizeConsole(800,600);
	gotoxy(35, 2);
	cout << "DANH SACH CHUYEN BAY KHOI HANH TRONG NGAY ";
	gotoxy(42,3); cout<<"Noi den: "; // 46,3
	
		gotoxy(tabx, taby);
	cout << char(218);
	//-------- dong dau
	for(int i = 1; i < tabs + 11; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	
	//cot dau
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx, taby + i);
		cout << char(179);
	}
	//cot cuoi
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + tabs + 11, taby + i);
		cout << char(179) ;
	}
	
	gotoxy(tabx , taby + tabw);
	cout << char(192); // L
	//dong cuoi
	for(int i = 1; i < tabs + 11; i++)
	{
		gotoxy(tabx + i, taby + tabw);
		cout << char(196);
	}
	gotoxy(tabx + tabs + 11 , taby + tabw);
	cout << char(217); // _|

	// STT
	gotoxy(tabx + 3, taby + 1); cout << "STT";
	gotoxy(tabx + 8, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 8, taby + i); cout << char(179); // cot stt
	}
	
	gotoxy(tabx, taby + 2);
	cout << char(195);
	// dong hai
	for(int i = 1; i < tabs + 11; i++)
	{
		gotoxy(tabx + i, taby + 2);
		cout << char(196);
	}
	gotoxy(tabx + 8, taby + 2); cout << char(197);
	gotoxy(tabx + tabs + 11, taby + 2); cout << char(180); //-|
	gotoxy(tabx + 8, taby + tabw); cout << char(193);

	// SO HIEU MB
	gotoxy(tabx + 9, taby + 1); cout << "SO HIEU MB";
	gotoxy(tabx + 20, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 20, taby + i); cout << char(179);
	}
	gotoxy(tabx + 20, taby + 2); cout << char(197);
	gotoxy(tabx + 20, taby + tabw); cout << char(193);

	// MA CHUYEN BAY
	gotoxy(tabx + 23, taby + 1); cout << "MA CHUYEN BAY";
	gotoxy(tabx + 38, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 38, taby + i); cout << char(179);
	}
	gotoxy(tabx + 38, taby + 2); cout << char(197);
	gotoxy(tabx + 38, taby + tabw); cout << char(193);

	// NGAY
	gotoxy(tabx + 45, taby + 1); cout << "NGAY";
	gotoxy(tabx + 55, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 55, taby + i); cout << char(179);
	}
	gotoxy(tabx + 55, taby + 2); cout << char(197);
	gotoxy(tabx + 55, taby + tabw); cout << char(193);
	
	// GIO
	gotoxy(tabx + 60, taby + 1); cout << "GIO";
	gotoxy(tabx + 68, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 68, taby + i); cout << char(179);
	}
	gotoxy(tabx + 68, taby + 2); cout << char(197);
	gotoxy(tabx + 68, taby + tabw); cout << char(193);
	
	// SAN BAY DEN
	gotoxy(tabx + 70, taby + 1); cout<<"SAN BAY DEN";
	gotoxy(tabx + 83, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 83, taby + i); cout << char(179);
	}
	gotoxy(tabx + 83, taby + 2); cout << char(197);
	gotoxy(tabx + 83, taby + tabw); cout << char(193);
	
	gotoxy(tabx + 84, taby + 1); cout<<"TRANG THAI";
	BoxTrangThai(ColorWHITE);

}

void Box_DS_Thong_Ke_So_Luot_Bay()
{
	

	gotoxy(tabx+20-20-20+5 , taby-2);
    SetColor(ColorGREEN);cout << "<-- THONG KE SO LUOT THUC HIEN CHUYEN BAY CUA TUNG MAY BAY THEO THU TU GIAM DAN -->";
    SetColor(255);
	gotoxy(tabx+20-20, taby);
	cout << char(218);
	//-------- dong dau
	for(int i = 1; i < tabs - 33 ; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	
	//cot dau
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx+20-20, taby + i);
		cout << char(179);
	}
	//cot cuoi
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + tabs - 13-20, taby + i);
		cout << char(179) ;
	}
	
	gotoxy(tabx+20-20, taby + tabw);
	cout << char(192);
	//dong cuoi
	for(int i = 1; i < tabs - 33; i++)
	{
		gotoxy(tabx + i + 20-20, taby + tabw);
		cout << char(196);
	}
	gotoxy(tabx + tabs - 13-20, taby + tabw);
	cout << char(217);

	// SO HIEU MAY BAY
	gotoxy(tabx + 26-20, taby + 1); cout << "SO HIEU MAY BAY";
	gotoxy(tabx + 45-20, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 45-20, taby + i); cout << char(179); // cot stt
	}
	
	gotoxy(tabx + 20-20, taby + 2);
	cout << char(195);
	// dong hai
	for(int i = 1; i < tabs - 33 ; i++)
	{
		gotoxy(tabx + i-20 + 20, taby + 2);
		cout << char(196);
	}
	gotoxy(tabx + 45-20, taby + 2); cout << char(197);
	gotoxy(tabx + tabs -20 - 13, taby + 2); cout << char(180);
	gotoxy(tabx + 45-20, taby + tabw); cout << char(193);

	// SO LUOT BAY
	gotoxy(tabx + 53-20, taby + 1); cout << "SO LUOT BAY";

}


void TableMayBay()
{

	gotoxy(tabx, taby);
	cout << char(218);
	for(int i = 1; i < tabs - 13; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx, taby + i);
		cout << char(179);
	}

	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + tabs - 13, taby + i);
		cout << char(179);
	}
	gotoxy(tabx, taby + tabw);
	cout << char(192);
	for(int i = 1; i < tabs - 13; i++)
	{
		gotoxy(tabx + i, taby + tabw);
		cout << char(196);
	}
	gotoxy(tabx + tabs - 13, taby + tabw);
	cout << char(217);

	// STT
	gotoxy(tabx + 3, taby + 1); cout << "STT";
	gotoxy(tabx + 8, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 8, taby + i); cout << char(179);
	}
	gotoxy(tabx, taby + 2);
	cout << char(195);
	for(int i = 1; i < tabs - 13; i++)
	{
		gotoxy(tabx + i, taby + 2);
		cout << char(196);
	}
	gotoxy(tabx + 8, taby + 2); cout << char(197);
	gotoxy(tabx + tabs - 13, taby + 2); cout << char(180);
	gotoxy(tabx + 8, taby + tabw); cout << char(193);

	// SO HIEU
	gotoxy(tabx + 15, taby + 1); cout << "SO HIEU";
	gotoxy(tabx + 27, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 27, taby + i); cout << char(179);
	}
	gotoxy(tabx + 27, taby + 2); cout << char(197);
	gotoxy(tabx + 27, taby + tabw); cout << char(193);

	// LOAI
	gotoxy(tabx + 37, taby + 1); cout << "LOAI";
	gotoxy(tabx + 55, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabx + 55, taby + i); cout << char(179);
	}
	gotoxy(tabx + 55, taby + 2); cout << char(197);
	gotoxy(tabx + 55, taby + tabw); cout << char(193);

	// SO CHO
	gotoxy(tabx + 58, taby + 1); cout << "SO CHO";

	
}
void TableChuyenBay()
{

	gotoxy(30,3);
	
	gotoxy(tabxCB, taby);
	cout << char(218);
	//-------- dong dau
	for(int i = 1; i < tabs + 11; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	
	//cot dau
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabxCB, taby + i);
		cout << char(179);
	}
	//cot cuoi
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabxCB + tabs + 11, taby + i);
		cout << char(179) ;
	}
	
	gotoxy(tabxCB , taby + tabw);
	cout << char(192); // L
	//dong cuoi
	for(int i = 1; i < tabs + 11; i++)
	{
		gotoxy(tabxCB + i, taby + tabw);
		cout << char(196);
	}
	gotoxy(tabxCB + tabs + 11 , taby + tabw);
	cout << char(217); // _|

	// STT
	gotoxy(tabxCB + 3, taby + 1); cout << "STT";
	gotoxy(tabxCB + 8, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabxCB + 8, taby + i); cout << char(179); // cot stt
	}
	
	gotoxy(tabxCB, taby + 2);
	cout << char(195);
	// dong hai
	for(int i = 1; i < tabs + 11; i++)
	{
		gotoxy(tabxCB + i, taby + 2);
		cout << char(196);
	}
	gotoxy(tabxCB + 8, taby + 2); cout << char(197);
	gotoxy(tabxCB + tabs + 11, taby + 2); cout << char(180); //-|
	gotoxy(tabxCB + 8, taby + tabw); cout << char(193);

	// SO HIEU MB
	gotoxy(tabxCB + 9, taby + 1); cout << "SO HIEU MB";
	gotoxy(tabxCB + 20, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabxCB + 20, taby + i); cout << char(179);
	}
	gotoxy(tabxCB + 20, taby + 2); cout << char(197);
	gotoxy(tabxCB + 20, taby + tabw); cout << char(193);

	// MA CHUYEN BAY
	gotoxy(tabxCB + 23, taby + 1); cout << "MA CHUYEN BAY";
	gotoxy(tabxCB + 38, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabxCB + 38, taby + i); cout << char(179);
	}
	gotoxy(tabxCB + 38, taby + 2); cout << char(197);
	gotoxy(tabxCB + 38, taby + tabw); cout << char(193);

	// NGAY
	gotoxy(tabxCB + 45, taby + 1); cout << "NGAY";
	gotoxy(tabxCB + 55, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabxCB + 55, taby + i); cout << char(179);
	}
	gotoxy(tabxCB + 55, taby + 2); cout << char(197);
	gotoxy(tabxCB + 55, taby + tabw); cout << char(193);
	
	// GIO
	gotoxy(tabxCB + 60, taby + 1); cout << "GIO";
	gotoxy(tabxCB + 68, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabxCB + 68, taby + i); cout << char(179);
	}
	gotoxy(tabxCB + 68, taby + 2); cout << char(197);
	gotoxy(tabxCB + 68, taby + tabw); cout << char(193);
	
	// SAN BAY DEN
	gotoxy(tabxCB + 70, taby + 1); cout<<"SAN BAY DEN";
	gotoxy(tabxCB + 83, taby); cout << char(194);
	for(int i = 1; i < tabw + 1; i++)
	{
		gotoxy(tabxCB + 83, taby + i); cout << char(179);
	}
	gotoxy(tabxCB + 83, taby + 2); cout << char(197);
	gotoxy(tabxCB + 83, taby + tabw); cout << char(193);
	
	gotoxy(tabxCB + 84, taby + 1); cout<<"TRANG THAI";
	BoxTrangThai(ColorBLACK);
}
int XacNhanSua()
{
	int x = 90, y = 19;
	gotoxy(85, 15);
	SetColor(ColorBLACK);
	SetBGColor(ColorDARKWHITE);
	cout << "                                ";
	gotoxy(85, 16); cout << "                                ";
	gotoxy(85, 17); cout << "    BAN CO CHAC CHAN SUA KHONG? ";
	gotoxy(85, 18); cout << "                                ";
	gotoxy(85, 19); cout << "     YES                NO      ";
	gotoxy(85, 20); cout << "                                ";
	int keyhit;
	do{
		gotoxy(90, 19);
//		SetColor(ColorDARKCYAN);
		switch(x)
		{
		case 90 : gotoxy(90, 19); cout << "YES"; break;
		case 109 : gotoxy(109, 19); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(90, 19);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 90 : gotoxy(90, 19); cout << "YES"; break;
			case 109 : gotoxy(109, 19); cout << "NO"; break;
			}
			x -= 19;
			if(x != 90)
			{
				x = 109;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(90, 19);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 90 : gotoxy(90, 19); cout << "YES"; break;
			case 109 : gotoxy(109, 19); cout << "NO"; break;
			}
			x += 19;
			if(x != 109)
			{
				x = 90;
			}
		}
		else if(x == 90 && keyhit == ENTER)
		{
			gotoxy(boxx + 22, 29);
			cout << "LUU FILE THANH CONG";
		
		    XoaManHinhTrungTam();
				
			SetBGColor(ColorBLACK);
			return 1;
		}
		else if(x == 109 && keyhit == ENTER)
		{
			XoaManHinhTrungTam();

		//	SetBGColor(ColorBLACK);
			return 0;
		}
	}while(true);
}



int XacNhanXoa()
{
	int x = 90, y = 19;
	gotoxy(85, 15);
	SetColor(ColorBLACK);
	SetBGColor(ColorDARKWHITE);
	cout << "                                ";
	gotoxy(85, 16); cout << "                                ";
	gotoxy(85, 17); cout << "    BAN CO CHAC CHAN XOA KHONG? ";
	gotoxy(85, 18); cout << "                                ";
	gotoxy(85, 19); cout << "     YES                NO      ";
	gotoxy(85, 20); cout << "                                ";
	int keyhit;
	do{
		gotoxy(90, 19);
//		SetColor(ColorDARKCYAN);
		switch(x)
		{
		case 90 : gotoxy(90, 19); cout << "YES"; break;
		case 109 : gotoxy(109, 19); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(90, 19);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 90 : gotoxy(90, 19); cout << "YES"; break;
			case 109 : gotoxy(109, 19); cout << "NO"; break;
			}
			x -= 19;
			if(x != 90)
			{
				x = 109;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(90, 19);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 90 : gotoxy(90, 19); cout << "YES"; break;
			case 109 : gotoxy(109, 19); cout << "NO"; break;
			}
			x += 19;
			if(x != 109)
			{
				x = 90;
			}
		}
		else if(x == 90 && keyhit == ENTER)
		{
			gotoxy(boxx + 22, 29);
			cout << "LUU FILE THANH CONG";
		
		    XoaManHinhTrungTam();
				
			SetBGColor(ColorBLACK);
			return 1;
		}
		else if(x == 109 && keyhit == ENTER)
		{
			XoaManHinhTrungTam();

		//	SetBGColor(ColorBLACK);
			return 0;
		}
	}while(true);
}

int XacNhanSaveFile()
{
	int x = 90, y = 19;
	gotoxy(85, 15);
	SetColor(ColorBLACK);
	SetBGColor(ColorDARKWHITE);
	cout << "                                ";
	gotoxy(85, 16); cout << "                                ";
	gotoxy(85, 17); cout << "  BAN CO MUON SAVE FILE KHONG?  ";
	gotoxy(85, 18); cout << "                                ";
	gotoxy(85, 19); cout << "     YES                NO      ";
	gotoxy(85, 20); cout << "                                ";
	int keyhit;
	do{
		gotoxy(90, 19);
//		SetColor(ColorDARKCYAN);
		switch(x)
		{
		case 90 : gotoxy(90, 19); cout << "YES"; break;
		case 109 : gotoxy(109, 19); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(90, 19);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 90 : gotoxy(90, 19); cout << "YES"; break;
			case 109 : gotoxy(109, 19); cout << "NO"; break;
			}
			x -= 19;
			if(x != 90)
			{
				x = 109;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(90, 19);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 90 : gotoxy(90, 19); cout << "YES"; break;
			case 109 : gotoxy(109, 19); cout << "NO"; break;
			}
			x += 19;
			if(x != 109)
			{
				x = 90;
			}
		}
		else if(x == 90 && keyhit == ENTER)
		{
			gotoxy(boxx + 22, 29);
			cout << "LUU FILE THANH CONG";
		
		    XoaManHinhTrungTam();
				
			SetBGColor(ColorBLACK);
			return 1;
		}
		else if(x == 109 && keyhit == ENTER)
		{
			XoaManHinhTrungTam();

		//	SetBGColor(ColorBLACK);
			return 0;
		}
	}while(true);
}
int XacNhanThemHKTiepTuc()
{
	int x = 90, y = 19;
	gotoxy(85, 15);
	SetColor(ColorBLACK);
	SetBGColor(ColorDARKWHITE);
	cout << "                                ";
	gotoxy(85, 16); cout << "                                ";
	gotoxy(85, 17); cout << "  BAN CO MUON THEM TIEP KHONG?  ";
	gotoxy(85, 18); cout << "                                ";
	gotoxy(85, 19); cout << "     YES                NO      ";
	gotoxy(85, 20); cout << "                                ";
	int keyhit;
	do{
		gotoxy(90, 19);
//		SetColor(ColorDARKCYAN);
		switch(x)
		{
		case 90 : gotoxy(90, 19); cout << "YES"; break;
		case 109 : gotoxy(109, 19); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(90, 19);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 90 : gotoxy(90, 19); cout << "YES"; break;
			case 109 : gotoxy(109, 19); cout << "NO"; break;
			}
			x -= 19;
			if(x != 90)
			{
				x = 109;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(90, 19);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 90 : gotoxy(90, 19); cout << "YES"; break;
			case 109 : gotoxy(109, 19); cout << "NO"; break;
			}
			x += 19;
			if(x != 109)
			{
				x = 90;
			}
		}
		else if(x == 90 && keyhit == ENTER)
		{
			
			
			return 1;
		}
		else if(x == 109 && keyhit == ENTER)
		{
	
			return 0;
		}
	}while(true);
}

int XacNhanHuyVe()
{	
		int maunen = 255; int mauchu = 12;
    XoaManHinhThongBao1();
	int x = 14, y = 31;
	gotoxy(15, 14);
	SetColor(ColorWHITE);
	SetBGColor(ColorBLACK);
					
	//VeHCN(6, 11,33,5,12);
	gotoxy(7,11); SetBGColor(maunen);SetColor(maunen);  cout<<"                               ";
	gotoxy(7,12); SetBGColor(maunen);SetColor(maunen);  cout<<"                               ";
	gotoxy(7, 13);SetBGColor(maunen);SetColor(mauchu);cout << "   BAN CO MUON HUY VE KHONG ?  ";
	gotoxy(7,14); SetBGColor(maunen);SetColor(mauchu);  cout<<"                               ";
	gotoxy(7, 15); SetBGColor(maunen);SetColor(maunen);cout <<"                               ";
	gotoxy(7,16); SetBGColor(maunen);SetColor(mauchu);  cout<<"                               ";
	
		int keyhit;
	do{
		gotoxy(14, 14);
//		SetColor(ColorBLACK);
		switch(x)
		{
		case 14 : gotoxy(15-1, 14+1);SetColor(1); cout << "YES"; gotoxy(34-1-2, 14+1);SetColor(0);cout << "NO";gotoxy(15-1, 14+1); break;
		case 31 : gotoxy(34-1-2, 14+1);SetColor(1); cout << "NO"; gotoxy(15-1, 14+1);SetColor(0); cout << "YES"; gotoxy(34-1-2, 14+1); break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(14, 14);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 14 : gotoxy(15-1, 14+1); cout << "YES"; break;
			case 31 : gotoxy(34-1-2, 14+1); cout << "NO"; break;
			}
			x -= 17;
			if(x != 14)
			{
				x = 31;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(31, 14);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 14 : gotoxy(15-1, 14+1); cout << "YES"; break;
			case 31 : gotoxy(34-1-2, 14+1); cout << "NO"; break;
			}
			x += 17;
			if(x != 31)
			{
				x = 14;
			}
		}
		else if(x == 14 && keyhit == ENTER)
		{
				SetBGColor(ColorBLACK);
			SetColor(255);
			gotoxy(6,11);cout<<"                                 ";
			gotoxy(6,12);cout<<"                                 ";
			gotoxy(6,13);cout<<"                                 ";
			gotoxy(6,14);cout<<"                                 ";
			gotoxy(6,15);cout<<"                                 ";
			gotoxy(6,16);cout<<"                                 ";
			gotoxy(12, 18);
			cout << "<HUY VE THANH CONG>";SetColor(ColorWHITE);
		
			return 1;
		}
		else if(x == 31 && keyhit == ENTER)
		{
				SetBGColor(ColorBLACK);
			SetColor(255);
			gotoxy(6,11);cout<<"                                 ";
			gotoxy(6,12);cout<<"                                 ";
			gotoxy(6,13);cout<<"                                 ";
			gotoxy(6,14);cout<<"                                 ";
			gotoxy(6,15);cout<<"                                 ";
			gotoxy(6,16);cout<<"                                 ";
			//system("cls");
			cout << "<HUY VE THAt BAI >";SetColor(ColorWHITE);
		//	SetBGColor(ColorBLACK);
			return 0;
		}
	}while(true);
}

int XacNhanDatVe()
{
	int maunen = 255; int mauchu = 12;
    XoaManHinhThongBao1();
	int x = 14, y = 31;
	gotoxy(15, 14);
	SetColor(ColorWHITE);
	SetBGColor(ColorBLACK);
					
	//VeHCN(6, 11,33,5,12);
	gotoxy(7,11); SetBGColor(maunen);SetColor(maunen);  cout<<"                               ";
	gotoxy(7,12); SetBGColor(maunen);SetColor(maunen);  cout<<"                               ";
	gotoxy(7, 13);SetBGColor(maunen);SetColor(mauchu);cout << "   BAN CO MUON DAT VE KHONG ?  ";
	gotoxy(7,14); SetBGColor(maunen);SetColor(mauchu);  cout<<"                               ";
	gotoxy(7, 15); SetBGColor(maunen);SetColor(maunen);cout <<"                               ";
	gotoxy(7,16); SetBGColor(maunen);SetColor(mauchu);  cout<<"                               ";
	
		int keyhit;
	do{
		gotoxy(14, 14);
//		SetColor(ColorBLACK);
		switch(x)
		{
		case 14 : gotoxy(15-1, 14+1);SetColor(1); cout << "YES"; gotoxy(34-1-2, 14+1);SetColor(0);cout << "NO";gotoxy(15-1, 14+1); break;
		case 31 : gotoxy(34-1-2, 14+1);SetColor(1); cout << "NO"; gotoxy(15-1, 14+1);SetColor(0); cout << "YES"; gotoxy(34-1-2, 14+1); break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(14, 14);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 14 : gotoxy(15-1, 14+1); cout << "YES"; break;
			case 31 : gotoxy(34-1-2, 14+1); cout << "NO"; break;
			}
			x -= 17;
			if(x != 14)
			{
				x = 31;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(31, 14);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 14 : gotoxy(15-1, 14+1); cout << "YES"; break;
			case 31 : gotoxy(34-1-2, 14+1); cout << "NO"; break;
			}
			x += 17;
			if(x != 31)
			{
				x = 14;
			}
		}
		else if(x == 14 && keyhit == ENTER)
		{
				SetBGColor(ColorBLACK);
			SetColor(255);
			gotoxy(6,11);cout<<"                                 ";
			gotoxy(6,12);cout<<"                                 ";
			gotoxy(6,13);cout<<"                                 ";
			gotoxy(6,14);cout<<"                                 ";
			gotoxy(6,15);cout<<"                                 ";
			gotoxy(6,16);cout<<"                                 ";
			gotoxy(12, 18+5);
			SetColor(10);
			cout << "<DAT VE THANH CONG>";SetColor(ColorWHITE);
		
			return 1;
		}
		else if(x == 31 && keyhit == ENTER)
		{
				SetBGColor(ColorBLACK);
			SetColor(255);
			gotoxy(6,11);cout<<"                                 ";
			gotoxy(6,12);cout<<"                                 ";
			gotoxy(6,13);cout<<"                                 ";
			gotoxy(6,14);cout<<"                                 ";
			gotoxy(6,15);cout<<"                                 ";
			gotoxy(6,16);cout<<"                                 ";
			//system("cls");
		//	SetBGColor(ColorBLACK);
			return 0;
		}
	}while(true);
}
int XacNhanThemHanhKhach()
{
	int maunen = 255; int mauchu = 12;
    XoaManHinhThongBao1();
	int x = 14-2;
	gotoxy(15, 14);
	SetColor(ColorWHITE);
	SetBGColor(ColorBLACK);
					
	//VeHCN(6, 11,33,5,12);
	gotoxy(7-2,11); SetBGColor(maunen);SetColor(maunen);  cout<<"                                  ";
	gotoxy(7-2,12); SetBGColor(maunen);SetColor(maunen);  cout<<"                                  ";
	gotoxy(7-2, 13);SetBGColor(maunen);SetColor(mauchu);cout << "  BAN MUON THEM HANH KHACH KHONG ?";
	gotoxy(7-2,14); SetBGColor(maunen);SetColor(mauchu);  cout<<"                                  ";
	gotoxy(7-2, 15); SetBGColor(maunen);SetColor(maunen);cout <<"                                  ";
	gotoxy(7-2,16); SetBGColor(maunen);SetColor(mauchu);  cout<<"                                  ";
//	gotoxy(15-1-2, 14+1);SetColor(1); cout << "YES"; gotoxy(34-1-2-2, 14+1);SetColor(0);cout << "NO";
		int keyhit;
	do{
		gotoxy(14-2, 14+1);
//		SetColor(ColorBLACK);
		switch(x)
		{
		case 14-2 : gotoxy(15-1-2, 14+1);SetColor(1); cout << "YES"; gotoxy(34-1-2-2, 14+1);SetColor(0);cout << "NO";gotoxy(15-1-2, 14+1); break;
		case 31-2 : gotoxy(34-1-2-2, 14+1);SetColor(1); cout << "NO"; gotoxy(15-1-2, 14+1);SetColor(0); cout << "YES"; gotoxy(34-1-2-2, 14+1); break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(14-2, 14);
//			SetColor(ColorDARKCYAN);
			switch(x)
			{
			case 14-2 : gotoxy(15-1-2, 14+1); cout << "YES"; break;
			case 31-2 : gotoxy(34-1-2-2, 14+1); cout << "NO"; break;
			}
			x -= 17;
			if(x != 14-2)
			{
				x = 31-2;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(31-2, 14);

			switch(x)
			{
			case 14-2 : gotoxy(15-1-2, 14+1); cout << "YES"; break;
			case 31-2 : gotoxy(34-1-2-2, 14+1); cout << "NO"; break;
			}
			x += 17;
			if(x != 31-2)
			{
				x = 14-2;
			}
		}
		else if(x == 14-2 && keyhit == ENTER)
		{
			SetBGColor(ColorBLACK);
			SetColor(255);
			gotoxy(6-2,11);cout<<"                                   ";
			gotoxy(6-2,12);cout<<"                                   ";
			gotoxy(6-2,13);cout<<"                                   ";
			gotoxy(6-2,14);cout<<"                                   ";
			gotoxy(6-2,15);cout<<"                                   ";
			gotoxy(6-2,16);cout<<"                                   ";
			gotoxy(12, 18+5);SetColor(10);
			cout << "< THEM HANH KHACH >";
			SetColor(255);
			return 1;
		}
		else if(x == 31-2 && keyhit == ENTER)
		{
			SetBGColor(ColorBLACK);
			SetColor(255);
			gotoxy(6-2,11);cout<<"                                   ";
			gotoxy(6-2,12);cout<<"                                   ";
			gotoxy(6-2,13);cout<<"                                   ";
			gotoxy(6-2,14);cout<<"                                   ";
			gotoxy(6-2,15);cout<<"                                   ";
			gotoxy(6-2,16);cout<<"                                   ";


			return 0;
		}
	}while(true);
}

void HienThiTrang(int tongtrang, int tranghientai, int x, int y)
{
	//textcolor(62);
	gotoxy(x, y + 1);
	cout << "Trang :  " << (tranghientai + 1) << " / " << tongtrang << "   ";
}


 // Note
void Del_Error() {
	SetColor(15);
	gotoxy(boxx+10, 29);
	for(int i = 0; i < 50; i++) cout << " ";
}

// Note
void Print_Error_MayBay(int i)
{
	Del_Error();
	string s;
	if (i == 1) s = "MA MAY BAY BI TRUNG!";
	gotoxy(boxx + 15, 29);
	cout<<"CANH BAO: "<<s;
}


//=====================================================================================================================================
//===============================                 XU LY CHUOI                ==========================================================
//=====================================================================================================================================







int Menu();


string nhapChuoiThemCB(int df,int x, int y){
	string s = "";
	
	while(true){
		char key = getch();
		switch(int(key)){
			case ESC:{
				return "exit";
				break;
			}
			case LEFT:{
				return "left";
				break;
			}
			case RIGHT:{
				return "right";
				break;
			}
			case ENTER:{
				return s;
				break;
			}
			case BACKSPACE:{
				if(s.length() > 0) s = s.substr(0,s.length()-1);
				else {
					s = "";
				}
				gotoxy(x,y); cout<<"                    ";
				gotoxy(x,y); cout<<s;
				break;
			}
			default:{
				if (s.length()<df && key!=LEFT && key!=RIGHT && 
					key!=-32 &&key!=UP && key!=DOWN && ((key>=48 && key<=57) || (key>=65 && key<=90) || (key>=97 && key <=122)))
				{
					s+= char(key);
					gotoxy(x,y); cout<<"                    ";
					gotoxy(x,y); cout<<s;
				}
				
				break;
			}
		}
	}

}



string nhapChuoi(int df,int x, int y){
	string s = "";
	
	while(true){
		char key = getch();
		switch(int(key)){
			case ESC:{
				return "exit";
				break;
			}
			case ENTER:{
				return s;
				break;
			}
			case BACKSPACE:{
				if(s.length() > 0) s = s.substr(0,s.length()-1);
				else {
					s = "";
				}
				gotoxy(x,y); cout<<"                    ";
				gotoxy(x,y); cout<<s;
				break;
			}
			default:{
				if (s.length()<df && key!=LEFT && key!=RIGHT && 
					key!=-32 &&key!=UP && key!=DOWN && ((key>=48 && key<=57) || (key>=65 && key<=90) || (key>=97 && key <=122)))
				{
					s+= char(key);
					gotoxy(x,y); cout<<"                    ";
					gotoxy(x,y); cout<<s;
				}
				
				break;
			}
		}
	}

}
string nhapChuoiHo(int df,int x, int y){
	string s = "";
	
	while(true){
		char key = getch();
		switch(int(key)){
			case ESC:{
				return "exit";
				break;
			}
			case ENTER:{
				return s;
				break;
			}
			case BACKSPACE:{
				if(s.length() > 0) s = s.substr(0,s.length()-1);
				else {
					s = "";
				}
				gotoxy(x,y); cout<<"                    ";
				gotoxy(x,y); cout<<s;
				break;
			}
			default:{
				if (s.length()<df && key!=LEFT && key!=RIGHT && 
					key!=-32 &&key!=UP && key!=DOWN && ( (key>=65 && key<=90) || (key>=97 && key <=122) ))
				{
					s+= char(key);
					gotoxy(x,y); cout<<"                    ";
					gotoxy(x,y); cout<<s;
				}
				
				break;
			}
		}
	}

}




string nhapChuoiTen(int df,int x, int y){
	string s = "";
	
	while(true){
		char key = getch();
		switch(int(key)){
			case ESC:{
				return "exit";
				break;
			}
			case ENTER:{
				return s;
				break;
			}
			case BACKSPACE:{
				if(s.length() > 0) s = s.substr(0,s.length()-1);
				else {
					s = "";
				}
				gotoxy(x,y); cout<<"                    ";
				gotoxy(x,y); cout<<s;
				break;
			}
			default:{
				if (s.length()<df && key!=LEFT && key!=RIGHT && 
					key!=-32 &&key!=UP && key!=DOWN && ( (key>=65 && key<=90) || (key>=97 && key <=122) || key == 32 ))
				{
					s+= char(key);
					gotoxy(x,y); cout<<"                    ";
					gotoxy(x,y); cout<<s;
				}
				
				break;
			}
		}
	}

}
string nhapSo(int so,int x, int y){
	string s = "";
	while(true){
		char key = getch();
		switch(int(key)){
			case ESC:{
				return "exit";
				break;
			}
			case ENTER:{
				return s;
				break;
			}
			case BACKSPACE:{
				if(s.length() > 0) s = s.substr(0,s.length()-1);
				else {
					s = "";
				}
				gotoxy(x,y); cout<<"                    ";
				gotoxy(x,y); cout<<s;
				break;
			}
			default:{
				if (s.length() < so && key>=48   && key<=57  )
				{
					s+= char(key);
					gotoxy(x,y); cout<<"                    ";
					gotoxy(x,y); cout<<s;
				}
				break;
			}
		}
	}
}
//=====================================================================================================================================
//===============================                 YEU CAU DE BAI              =========================================================
//=====================================================================================================================================







void NhapMayBay(ListMayBay &lmb)
{

		
	int keyhit,x = 28;
	int demfield = 0;
	while (true)
	{
		if (Full_MB(lmb))
		{
			gotoxy(boxx + 14, boxy + 10); cout<<"SO LUONG MAY BAY DAT GIOI HAN";
		  
			gotoxy(boxx + 14, boxy + 10); cout<<"                             ";
			break;
		}
		else
		{
			XoaManHinhTrungTam(); // xoa noi dung
			XoaManHinhHuongDan();// xoa thong bao


			cout << "< THEM MAY BAY >";
			logo(3,10);


			HuongDanThemDS();
			Box_NhapMayBay();
			MayBay mb;
			strcpy(mb.soHieuMB, "");
			strcpy(mb.loaiMB, "");
			mb.soCho = 0;
	
				bool trung;
				// NHAP SO HIEU MAY BAY
				SoHieuMB: 	
				do{
				
					gotoxy(boxx + 28, boxy + 2); 
					string tmp = nhapChuoi(15,boxx + 28, boxy + 2);
					
					if(tmp == "exit"){
						goto THOAT;
					}
					strcpy(mb.soHieuMB, tmp.c_str()); 
					strcpy(mb.soHieuMB, fix_Ma(mb.soHieuMB));	
					
					if (CheckSoHieu_MB(lmb, mb.soHieuMB) != -1)
					{	
						gotoxy(boxx + 14, boxy + 10); cout<<"SO HIEU MAY BAY TRUNG!";
						Sleep(500);  
						gotoxy(boxx + 14, boxy + 10); cout<<"                          ";
						gotoxy(boxx + 28, boxy + 2);  cout<<"                        ";
						goto SoHieuMB;
					}
					else if (strcmp(mb.soHieuMB, "\0") == 0)
					{
						gotoxy(boxx + 14, boxy + 10); cout<<"KHONG BO TRONG !";
						Sleep(500);  
						gotoxy(boxx + 14, boxy + 10); cout<<"                                 ";
						gotoxy(boxx + 28, boxy + 2);  cout<<"                                 ";
						goto SoHieuMB;
					}
					else
					{
						demfield++;
						gotoxy(boxx + 28, boxy + 2);  cout<<"                                 ";
						gotoxy(boxx + 28, boxy + 2); cout<<mb.soHieuMB;
						trung = true;
					}	
				}while(trung == false);

		//		if (strcmp(mb.soHieuMB, "") == 0) break;
			
			LoaiMB:	
				// NHAP LOAI MAY BAY
				do{
					trung = false;
					gotoxy(boxx + 28, boxy + 4);
					string tmp = nhapChuoi(15,boxx + 28, boxy + 4);
	
					if(tmp == "exit"){
						goto THOAT;
					}
					strcpy(mb.loaiMB, tmp.c_str()); 
					strcpy(mb.loaiMB, fix_HoTen(mb.loaiMB));
					
					if (strcmp(mb.loaiMB, "\0") == 0)
					{
						gotoxy(boxx + 14, boxy + 10); cout<<"KHONG BO TRONG!";
						Sleep(1000);  
						gotoxy(boxx + 14, boxy + 10); cout<<"                                 ";
						gotoxy(boxx + 28, boxy + 4);  cout<<"                                 ";
						goto LoaiMB;
					}
					else
					{
						demfield++;
						gotoxy(boxx + 28, boxy + 4);  cout<<"                                 ";
						gotoxy(boxx + 28, boxy + 4);cout<<mb.loaiMB;
						trung = true;
					}
				}while(trung == false);
				if (strcmp(mb.loaiMB, "") == 0) break;
		SoCho:			
				// NHAP SO CHO MAY BAY >= 20
				do{
					trung = false;
					gotoxy(boxx + 28, boxy + 6);
					char cho[10];
					string tmp = nhapSo(4,boxx + 28, boxy + 6);
	
					if(tmp == "exit"){
						break;
					}
					strcpy(cho, tmp.c_str()); 
					
					strcpy(cho, fix_Ma(cho));
					if (strcmp(cho, "\0") == 0)
					{
						gotoxy(boxx + 14, boxy + 10); cout<<"KHONG BO TRONG";
						Sleep(1000);  
						gotoxy(boxx + 14, boxy + 10); cout<<"                                ";
						gotoxy(boxx + 28, boxy + 6);  cout<<"                                ";
						goto SoCho;
					}
					else
					{
						int check = check_Chuoi_Char(cho);
						if (check == 1)
						{
							int soCho = atoi(cho);
							if (soCho < 20)
							{
								gotoxy(boxx + 14, boxy + 10); cout<<"CHI NHAN SO VA PHAI LON HON 20!";
								Sleep(1000);  
								gotoxy(boxx + 14, boxy + 10); cout<<"                                 ";
								gotoxy(boxx + 28, boxy + 6);  cout<<"                                 ";
								goto SoCho;
							}
							else
							{
								demfield++;
								mb.soCho = soCho;
								gotoxy(boxx + 28, boxy + 6);  cout<<"                                 ";
								gotoxy(boxx + 28, boxy + 6);cout<<mb.soCho;
								trung = true;
							}
						}
						else
						{
							gotoxy(boxx + 14, boxy + 10); cout<<"SO CHO CHI NHAN SO!";
							Sleep(1000);  
							gotoxy(boxx + 14, boxy + 10); cout<<"                    ";
							gotoxy(boxx + 28, boxy + 6);  cout<<"                    ";
							goto SoCho;
						}
						
					}
			
				}while(trung == false);
				if (mb.soCho == 0) break;
				
				if (demfield == 3)
				{
					Insert_MB(lmb, mb);
					gotoxy(boxx + 14, boxy + 10); cout<<"DA THEM THANH CONG";
					Sleep(1500);  
					gotoxy(boxx + 14, boxy + 10); cout<<"                             ";
					demfield = 0;
				}	
		}
		
		
	}
	THOAT:
	int a = XacNhanSaveFile();
	if(a == 1)
	{
		ofstream fileout;
		fileout.open("maybay.txt", ios::out);
		LuuFileMayBay(lmb,fileout);
	}
	
}
void frame_NhapMaMayBay(int x, int y)
{
	gotoxy(x, y); SetBGColor(ColorBLACK); SetColor(ColorWHITE);	cout << "    NHAP VAO SO HIEU MAY BAY    ";
	gotoxy(x, y + 1); SetBGColor(ColorBLACK);		cout << "     ";
	gotoxy(x + 5, y + 1);  SetBGColor(ColorWHITE); 	cout << "                       ";
	gotoxy(x + 27, y + 1); SetBGColor(ColorBLACK); 	cout << "     ";
	gotoxy(x, y + 2); SetBGColor(ColorBLACK);		cout << "                                ";
	SetBGColor(ColorBLACK); SetColor(ColorBLACK);
}
void frame_NhapMaChuyenBay(int x, int y)
{
	gotoxy(x, y); SetBGColor(ColorBLACK); SetColor(ColorWHITE);	cout << "     NHAP VAO MA CHUYEN BAY     ";
	gotoxy(x, y + 1); SetBGColor(ColorBLACK);		cout << "     ";
	gotoxy(x + 5, y + 1);  SetBGColor(ColorWHITE); 	cout << "                       ";
	gotoxy(x + 27, y + 1); SetBGColor(ColorBLACK); 	cout << "     ";
	gotoxy(x, y + 2); SetBGColor(ColorBLACK);		cout << "                                ";
	SetBGColor(ColorBLACK); SetColor(ColorBLACK);
}

MayBay *SearchMB(ListMayBay lmb, char sohieu[])
{
	
	for (int i = 0; i < lmb.soluong; i++){
		if (strcmp(lmb.maybay[i]->soHieuMB, sohieu) == 0)
			return lmb.maybay[i];
	}
	return NULL;
}

void SuaMayBay(ListMayBay &lmb){
		
	NhapMA:
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		
		XoaManHinhThongBao1();
		XoaManHinhHuongDan();
		HuongDanSuaMB();
		frame_NhapMaMayBay(3,16);
		char soHieu[15];
		gotoxy(8, 17); SetColor(ColorBLACK); SetBGColor(ColorWHITE);
		string ma = nhapChuoi(15,8,17);
		if (ma == "exit")
			return;
		strcpy(soHieu, ma.c_str());
		strcpy(soHieu, fix_Ma(soHieu));
		int x = CheckSoHieu_MB(lmb, soHieu);
		if (x == -1)
		{
			SetColor(ColorWHITE); SetBGColor(ColorBLACK);
			gotoxy(3,19); cout<<"Khong tim thay chuyen bay nay!";
			Sleep(1000);
			gotoxy(3,19); cout<<"            					";
			goto NhapMA;
		}
		
		while(1)
		{
			SetColor(ColorWHITE); SetBGColor(ColorBLACK);
			int demfield = 0;
			bool trung;
			XoaManHinhTrungTam(); // XOA NOI DUNG
			Box_SuaMayBay();
			MayBay *mb = SearchMB(lmb, soHieu);
			gotoxy(boxx + 27-28, boxy + 2); cout<<mb->soHieuMB;
			gotoxy(boxx + 27-28, boxy + 4); cout<<mb->loaiMB;
			gotoxy(boxx + 27-28, boxy + 6); cout<<mb->soCho;
			
			gotoxy(boxx + 61-28, boxy + 2); cout<<mb->soHieuMB;
			
			char loai[40];
			strcpy(loai,"");
			int cho_edit = 0;
			do{
					trung = false;
					gotoxy(boxx + 61-30, boxy + 4);
					string tmp = nhapChuoi(15,boxx + 61-30, boxy + 4);
	
					if(tmp == "exit"){
						break;
					}
					strcpy(loai, tmp.c_str()); 
					strcpy(loai, fix_HoTen(loai));
					
					if (strcmp(loai, "\0") == 0)
					{
						gotoxy(boxx + 14-30+20, boxy + 10); cout<<"KHONG BO TRONG!";
						Sleep(1000);  
						gotoxy(boxx + 14-30+20, boxy + 10); cout<<"                 ";
						gotoxy(boxx + 61-30, boxy + 4);  cout<<"            ";
					}
					else
					{
						demfield++;
						gotoxy(boxx + 61-30, boxy + 4);  cout<<"                 ";
						gotoxy(boxx + 61-30, boxy + 4);  cout<<loai;
						trung = true;
					}
				}while(trung == false);
				if (strcmp(loai, "") == 0) break;
				
				// NHAP SO CHO MAY BAY >= 20
				do{
					trung = false;
					gotoxy(boxx + 61-30, boxy + 6);
					char cho[10];
					
				
					string tmp = nhapSo(4,boxx + 61-30, boxy + 6);
	
					if(tmp == "exit"){
						break;
					}
					strcpy(cho, tmp.c_str()); 
					
					strcpy(cho, fix_Ma(cho));
					if (strcmp(cho, "\0") == 0)
					{
						gotoxy(boxx + 14-30+20, boxy + 10); cout<<"KHONG BO TRONG";
					//	Sleep(1000);  
						gotoxy(boxx + 14-30+20, boxy + 10); cout<<"               ";
						gotoxy(boxx + 61-30, boxy + 6);  cout<<"               ";
					}
					else
					{
						int soCho = atoi(cho);
						if (soCho < 20)
						{
							gotoxy(boxx + 14-30+20, boxy + 10); cout<<"CHI NHAN SO VA PHAI LON HON 20!";
						//	Sleep(1000);  
							gotoxy(boxx + 14-30+20, boxy + 10); cout<<"                                 ";
							gotoxy(boxx + 61-30, boxy + 6);  cout<<"            ";
						}
						else
						{
							demfield++;
							cho_edit = soCho;
							gotoxy(boxx + 61-30, boxy + 6);  cout<<"           ";
							gotoxy(boxx + 61-30, boxy + 6);  cout<<cho_edit;
							trung = true;
						}
					}
			
				}while(trung == false);
				if (cho_edit == 0) break;
			//	int a = ;
			
		
				if (demfield == 2 && XacNhanSua()==1)
				{
					for (int i = 0; i < lmb.soluong; i++){
						if (strcmp(lmb.maybay[i]->soHieuMB, mb->soHieuMB) == 0){
							strcpy(lmb.maybay[i]->loaiMB, loai);
							lmb.maybay[i]->soCho = cho_edit;
							break;
						}
					}
					
					gotoxy(boxx + 14-30+20, boxy + 10); cout<<"SUA THANH CONG";
				//	Sleep(1500);  
					gotoxy(boxx + 14-30+20, boxy + 10); cout<<"               ";
					ofstream fileout;
					fileout.open("maybay.txt", ios::out);
					LuuFileMayBay(lmb,fileout);
					demfield = 0;
					break;
				}	
		}
		
}

void SuaChuyenBay(SingleList_CB &lcb, ListMayBay lmb){
		
	NhapMA:
		
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		
		XoaManHinhThongBao1();
		
		XoaManHinhHuongDan();
		HuongDanSuaCB();
		
		frame_NhapMaChuyenBay(3,16);
		ChuyenBay cb_edit;
		
		char maCB[15];
		gotoxy(8, 17); SetColor(ColorPURPLE); SetBGColor(ColorWHITE);
		string ma = nhapChuoi(15,8,17);
		if (ma == "exit")
			return;
		strcpy(maCB, ma.c_str());
		strcpy(maCB, fix_Ma(maCB));
		
		Node_CB *pNode = SearchCB(lcb, maCB);
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		int x = Check_MaCB(lcb, maCB);
		if (x == -1)
		{
			SetColor(ColorWHITE); SetBGColor(ColorBLACK);
			gotoxy(3,19); cout<<"Khong tim thay chuyen bay";
			Sleep(1000);
			gotoxy(3,19); cout<<"            	       				";
			goto NhapMA;
		}
		else{
			
			
			int socho = getsocho(lmb, pNode->cb.soHieuMB);
			bool co_HK = CheckHKTrongCBHayKhong(pNode->cb.dsVe, socho);
			if (co_HK){
				gotoxy(3,19); cout<<"Da co hanh khach dat ve.";
				Sleep(1500);
				gotoxy(3,19); cout<<"            				";
				goto NhapMA;
			}
			else if(pNode->cb.trangThai == 3)//pNode->cb.trangThai == 0
			{
			gotoxy(3,19); cout<<"Chuyen bay nay da HOAN TAT";
			Sleep(1000);
			gotoxy(3,19); cout<<"            				";
			goto NhapMA;
			}
			else if(pNode->cb.trangThai == 0)
			{
			gotoxy(3,19); cout<<"Chuyen bay nay da HUY";
			Sleep(1500);
			gotoxy(3,19); cout<<"            		  ";
			goto NhapMA;
			}
			
		}
		

		while(1)
		{
//			SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		NhapLai:
			int demfield = 0;
			bool trung;
			XoaManHinhTrungTam();
			Box_SuaChuyenBayBay();
  			cb_edit = pNode->cb;
			gotoxy(boxx + 27-15, boxy - 6+5); cout<<cb_edit.soHieuMB;
			gotoxy(boxx + 27-15, boxy - 4+5); cout<<cb_edit.maCB;
			gotoxy(boxx + 27-15, boxy - 2+5); cout<<cb_edit.tgKhoiHanh.nam;
			gotoxy(boxx + 27-15, boxy  +5  ); cout<<cb_edit.tgKhoiHanh.thang;
			gotoxy(boxx + 27-15, boxy + 2+5); cout<<cb_edit.tgKhoiHanh.ngay;
			gotoxy(boxx + 27-15, boxy + 4+5); cout<<cb_edit.tgKhoiHanh.gio;
			gotoxy(boxx + 27-15, boxy + 6+5); cout<<cb_edit.tgKhoiHanh.phut;
			gotoxy(boxx + 27-15, boxy + 8+5); cout<<cb_edit.sanBayDen;
			
			gotoxy(boxx + 61-15, boxy - 6+5);  cout<<cb_edit.soHieuMB; 
			gotoxy(boxx + 61-15, boxy - 4+5);  cout<<cb_edit.maCB;
			gotoxy(boxx + 61-15, boxy + 8+5); cout<<cb_edit.sanBayDen;
			
			char loai[40];
			strcpy(loai,"");
			int nam_edit = 0, thang_edit = 0, ngay_edit = 0, gio_edit = 0, phut_edit = 0;
			// SUA NAM
				do{
					trung = false;
					gotoxy(boxx + 61-15, boxy - 2+5);
					char nam[10];
					string tmp = nhapSo(4,boxx + 61-15, boxy - 2+5);
	
					if(tmp == "exit"){
						break;
					}
					strcpy(nam, tmp.c_str()); 
					
					strcpy(nam, fix_Ma(nam));
					if (strcmp(nam, "\0") == 0)
					{
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG BO TRONG";
						Sleep(1000);  
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"               ";
						gotoxy(boxx + 61-15, boxy - 2+5);  cout<<"               ";
					}
					else
					{
						int check = check_Chuoi_Char(nam);
						if (check == 1)
						{
							int convert_nam = atoi(nam);
							if (convert_nam < 2020)
							{
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"NAM PHAI LON HON BANG 2020";
								Sleep(1000);  
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                           ";
								gotoxy(boxx + 61-15, boxy - 2+5);  cout<<"          ";
							}
							else
							{
								demfield++;
								nam_edit = convert_nam;
								gotoxy(boxx + 61-15, boxy - 2+5);  cout<<"          ";
								gotoxy(boxx + 61-15, boxy - 2+5);  cout<<nam_edit;
								trung = true;
							}
						}
						else
						{
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG DUOC CO CHU!";
							Sleep(1000);  
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                  ";
							gotoxy(boxx + 61-15, boxy - 2+5);  cout<<"                  ";
						}
						
					}
			
				}while(trung == false);
				if (nam_edit == 0) break;
				
				// SUA THANG
				do{
					trung = false;
					gotoxy(boxx + 61-15, boxy+5);
					char thang[10];
					string tmp = nhapSo(2,boxx + 61-15, boxy+5);
	
					if(tmp == "exit"){
						break;
					}
					strcpy(thang, tmp.c_str()); 
					
					strcpy(thang, fix_Ma(thang));
					if (strcmp(thang, "\0") == 0)
					{
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG BO TRONG";
						Sleep(1000);  
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"               ";
						gotoxy(boxx + 61-15, boxy+5);      cout<<"               ";
					}
					else
					{
						int check = check_Chuoi_Char(thang);
						if (check == 1)
						{
							int convert_thang = atoi(thang);
							if (convert_thang <= 0 || convert_thang > 12)
							{
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"THANG KHONG HOP LE";
								Sleep(1000);  
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                   ";
								gotoxy(boxx + 61-15, boxy+5);  cout<<"           ";
							}else if(Check_thang(convert_thang,nam_edit) == false){
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"THANG >= THANG HIEN TAI";
								Sleep(1000);  
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                       ";
								gotoxy(boxx + 61-15, boxy+5);  cout<<"           ";
							}
							else
							{
								demfield++;
								thang_edit = convert_thang;
								gotoxy(boxx + 61-15, boxy+5); cout<<"           ";
								gotoxy(boxx + 61-15, boxy+5); cout<<convert_thang;
								trung = true;
							}
						}
						else
						{
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG DUOC CO CHU!";
							Sleep(1000);  
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                  ";
							gotoxy(boxx + 61-15, boxy+5);      cout<<"                  ";
						}
					}
			
				}while(trung == false);
				if (thang_edit == 0) break;
				
				// SUA NGAY
				do{
					trung = false;
					gotoxy(boxx + 61-15, boxy + 2+5);
					char ngay[10];
					string tmp = nhapSo(2,boxx + 61-15, boxy + 2+5);
	
					if(tmp == "exit"){
						break;
					}
					strcpy(ngay, tmp.c_str()); 
					
					strcpy(ngay, fix_Ma(ngay));
					if (strcmp(ngay, "\0") == 0)
					{
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG BO TRONG";
						Sleep(1000);  
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"               ";
						gotoxy(boxx + 61-15, boxy + 2+5);  cout<<"               ";
					}
					else
					{
						int check = check_Chuoi_Char(ngay);
						if (check == 1)
						{
							int convert_ngay = atoi(ngay);
							if (convert_ngay <= 0 || convert_ngay > 31 || !Check_Date(nam_edit, thang_edit, convert_ngay))
							{
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"NGAY KHONG HOP LE";
								Sleep(1000);  
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                   ";
								gotoxy(boxx + 61-15, boxy + 2+5);  cout<<"           ";
							}else if(Check_Ngay(convert_ngay,thang_edit,nam_edit)== false){
								
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"NGAY >= NGAY HIEN TAI";
								Sleep(1000);  
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                     ";
								gotoxy(boxx + 61-15, boxy + 2+5);  cout<<"           ";
								
								
							}
							else
							{
								demfield++;
								ngay_edit = convert_ngay;
								gotoxy(boxx + 61-15, boxy + 2+5); cout<<"           ";
								gotoxy(boxx + 61-15, boxy + 2+5); cout<<convert_ngay;
								trung = true;
							}
						}
						else
						{
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG DUOC CO CHU!";
							Sleep(1000);  
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                  ";
							gotoxy(boxx + 61-15, boxy + 2+5);  cout<<"                  ";
						}
					}
			
				}while(trung == false);
				if (ngay_edit == 0) break;
				
				// SUA GIO
				do{
					trung = false;
					gotoxy(boxx + 61-15, boxy + 4+5);
					char gio[10];
					string tmp = nhapSo(2,boxx + 61-15, boxy + 4+5);
	
					if(tmp == "exit"){
						break;
					}
					strcpy(gio, tmp.c_str()); 
					
					strcpy(gio, fix_Ma(gio));
					if (strcmp(gio, "\0") == 0)
					{
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG BO TRONG";
						Sleep(1000);  
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"               ";
						gotoxy(boxx + 61-15, boxy + 4+5);  cout<<"               ";
					}
					else
					{
						int check = check_Chuoi_Char(gio);
						if (check == 1)
						{
							int convert_gio = atoi(gio);
							if (convert_gio < 0 || convert_gio > 23)
							{
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"GIO KHONG HOP LE";
								Sleep(1000);  
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                   ";
								gotoxy(boxx + 61-15, boxy + 4+5);  cout<<"           ";
							}
							else if(Check_Gio(convert_gio,ngay_edit,thang_edit,nam_edit)== false){
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"GIO >= GIO HIEN TAI  ";
								Sleep(1000);  
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                     ";
								gotoxy(boxx + 61-15, boxy + 4+5);  cout<<"           ";
							}
							else
							{
								demfield++;
								gio_edit = convert_gio;
								gotoxy(boxx + 61-15, boxy + 4+5); cout<<"           ";
								gotoxy(boxx + 61-15, boxy + 4+5); cout<<gio_edit;
								trung = true;
							}
						}
						else
						{
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG DUOC CO CHU!";
							Sleep(1000);  
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                  ";
							gotoxy(boxx + 61-15, boxy + 4+5);  cout<<"                  ";
						}
					}
			
				}while(trung == false);
				if (gio_edit == 0) break;
				
				// SUA PHUT
				do{
					trung = false;
					gotoxy(boxx + 61-15, boxy + 6+5);
					char phut[10];
					string tmp = nhapSo(2,boxx + 61-15, boxy + 6+5);
	
					if(tmp == "exit"){
						break;
					}
					strcpy(phut, tmp.c_str()); 
					
					strcpy(phut, fix_Ma(phut));
					if (strcmp(phut, "\0") == 0)
					{
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG BO TRONG";
						Sleep(1000);  
						gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                 ";
						gotoxy(boxx + 61-15, boxy + 6+5);  cout<<"               ";
					}
					else
					{
						int check = check_Chuoi_Char(phut);
						if (check == 1)
						{
							int convert_phut = atoi(phut);
							if (convert_phut < 0 || convert_phut > 59)
							{
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"PHUT KHONG HOP LE";
								Sleep(1000);  
								gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                   ";
								gotoxy(boxx + 61-15, boxy + 6+5);  cout<<"           ";
							}
							else
							{
								demfield++;
								phut_edit = convert_phut;
								gotoxy(boxx + 61-15, boxy+5); cout<<"           ";
								gotoxy(boxx + 61-15, boxy+5); cout<<phut_edit;
								trung = true;
							}
						}
						else
						{
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"KHONG DUOC CO CHU!";
							Sleep(1000);  
							gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                  ";
							gotoxy(boxx + 61-15, boxy + 6+5);  cout<<"                  ";
						}
					}
			
				}while(trung == false);
				if (phut_edit == 0) break;
				
				
				cb_edit.tgKhoiHanh.nam = nam_edit;
				cb_edit.tgKhoiHanh.thang = thang_edit;
				cb_edit.tgKhoiHanh.ngay = ngay_edit;
				cb_edit.tgKhoiHanh.gio = gio_edit;
				cb_edit.tgKhoiHanh.phut = phut_edit;
				if (!Check_ThoiGian_ChuyenBay(cb_edit.tgKhoiHanh)){
					gotoxy(boxx + 14-15, boxy + 12+5); cout<<"THOI GIAN CUA BAN DA QUA HAN";
					Sleep(1000);  
					gotoxy(boxx + 14-15, boxy + 12+5); cout<<"                            ";
					goto NhapLai;
				}
				
				
				if (demfield == 5 && XacNhanSua()==1)
				{
					pNode->cb = cb_edit;
					
					gotoxy(boxx + 14-15, boxy + 12+5); cout<<"SUA THANH CONG";
 
					gotoxy(boxx + 14-15, boxy + 12+5); cout<<"               ";
					LuuFileChuyenBay(lcb, lmb);
					
					demfield = 0;

					break;
				}	
		}
		
}

void XoaMayBay(ListMayBay &lmb, SingleList_CB lcb)
{
	NhapMA:
		
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		XoaManHinhThongBao1();
		XoaManHinhHuongDan();
		HuongDanXoaMB();
		frame_NhapMaMayBay(3,16);
		char soHieu[15];
		gotoxy(8, 17); SetColor(ColorBLACK); SetBGColor(ColorWHITE);
		string ma = nhapChuoi(15,8,17);
		if (ma == "exit")
			return;
		strcpy(soHieu, ma.c_str());
		strcpy(soHieu, fix_Ma(soHieu));
		int x = CheckSoHieu_MB(lmb, soHieu);
		if (x == -1)
		{
			SetColor(ColorWHITE); SetBGColor(ColorBLACK);
			gotoxy(3,19); cout<<"Khong tim thay chuyen bay nay!";
			Sleep(1000);
			gotoxy(3,19); cout<<"            					";
			goto NhapMA;
		}
		else
		{
			for (Node_CB *pNode = lcb.pHead; pNode != NULL; pNode=pNode->pNext)
			{
				if (strcmp(pNode->cb.soHieuMB, soHieu) == 0)
				{
					SetColor(ColorWHITE); SetBGColor(ColorBLACK);
					gotoxy(3,19); cout<<"May bay co hien co chuyen bay";
					gotoxy(3,20); cout<<"Khong the xoa!!";
				//	Sleep(1000);
					XoaManHinhThongBao1();
					goto NhapMA;
				}
			}
			int a = XacNhanXoa();
			if(a == 1)
			{
				for (int i = x; i < lmb.soluong; i++)
				{
				lmb.maybay[i] = lmb.maybay[i+1];
				}
				lmb.soluong--;
			}
		
			
		}
	
}

void Danh_Sach_MayBay(ListMayBay &lmb, SingleList_CB lcb)
{	
	
	Danhsach:
	int tmp = 0;
	XoaManHinhHuongDan();
	
	int trang = 0, tongtrang = 0;
	if (lmb.soluong <= 20)
	{
		trang = 0;
		tongtrang = 1;
	}
	else
	{
		tongtrang = (lmb.soluong / 21) + 1;
	}
	while(1)
	{
	Xuat:	
		XoaManHinhTrungTam();
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		

		TableMayBay();
		HienThiTrang(tongtrang, trang, 102, 39);
		HuongDanButton();
	
//		VeHCN( 0,0,40, 32+14,ColorWHITE); // ve man hinh thong bao doc
//		VeHCN( 0,0,166, 14+32,ColorWHITE);// ve BG
	//	VeHCN( 0,0,166, 8,ColorWHITE);// ve man hinh ngang
		XoaManHinhThongBao1();
		logo(3,10);
		VeHCN( 0,0,166, 8,ColorWHITE);
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		gotoxy(tabx + 4, taby + 3);
		int dem = 0;
		int tmpi = 0;
		for (int i = 0 + trang * 20; i < 20 + trang * 20 && i < lmb.soluong; i++)
		{
			gotoxy(tabx + 4, taby + 3 + dem); cout <<dem+1;
			gotoxy(tabx + 14, taby + 3 + dem); cout<<lmb.maybay[i]->soHieuMB;
			gotoxy(tabx + 35, taby + 3 + dem); cout <<lmb.maybay[i]->loaiMB;
			gotoxy(tabx + 60, taby + 3 + dem); cout <<lmb.maybay[i]->soCho;
			dem++;
			
			tmpi = i;
		}
		
		gotoxy(96, 38);
		cout << "[<-] Tro lai | Tiep Theo [->]"; 
		
		int c = 0;
		do{
			c = getch();
		}while(c != LEFT && c != RIGHT && c!= ESC && c != F1 && c != F2 && c != F3);
		if (c == ESC)
		{
			
			int a = XacNhanSaveFile();
			if(a == 1)
			{
				ofstream fileout;
				fileout.open("maybay.txt", ios::out);
				LuuFileMayBay(lmb, fileout);
			}
			XoaManHinhHuongDan();
			break;
		}
		else if (c == LEFT)
		{
			if(tongtrang > 1 && trang > 0)
			{
				trang--;
				goto Xuat;
			}
		}
		else if (c == RIGHT)
		{
			if(tongtrang > 1 && trang  + 1 < tongtrang)
			{
				trang++;
				goto Xuat;
			}
		}
		else if (c == F1)
		{
			
			NhapMayBay(lmb);
			goto Danhsach;
		//	goto Xuat;
		}
		else if (c == F2)
		{
	
			XoaMayBay(lmb, lcb);
	
			XoaManHinhHuongDan();

			goto Xuat;
		}
		else if (c == F3)
		{
		//	Sleep(500);
			SuaMayBay(lmb);

			XoaManHinhHuongDan();
			

			goto Xuat;
		}
	}	
}

void NhapChuyenBay(ListMayBay lmb, SingleList_CB &listCB)
{
	
	string CheckTrung;
	while (true)
	{
		int keyhit,xThongBao = 14, yThongBao = 12;
		int demfield = 0;
		int socho = 0;
		XoaManHinhTrungTam(); // xoa noi dung
		XoaManHinhHuongDan();
		
		HuongDanThemCB();
		logo(3,10);
		Box_NhapChuyenBayBay();
		gotoxy(100,10);cout<<"< THEM CHUYEN BAY >";
		ChuyenBay cb;
		strcpy(cb.soHieuMB, "");
		strcpy(cb.maCB, "");
		cb.tgKhoiHanh.ngay = -1;
		cb.tgKhoiHanh.thang = -1;
		cb.tgKhoiHanh.nam = -1;
		cb.tgKhoiHanh.gio = -1;
		cb.tgKhoiHanh.phut = -1;
		strcpy(cb.sanBayDen, "");
		cb.trangThai = 1;
		

			bool trung;
			// NHAP SO HIEU MAY BAY
			
			do{
				
				
				
					Danhsach:
	
					XoaManHinhHuongDan();
	
				int trang = 0, tongtrang = 0;
	if (lmb.soluong <= 8)
	{
		trang = 0;
		tongtrang = 1;
	}
	else
	{
		tongtrang = (lmb.soluong / 9) + 1;
	}

	Xuat:	
	//	XoaManHinhTrungTam();
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		XoaManHinh3();
		VeHCN(71,31+2,71,12,255);
		gotoxy(75,32+2);SetColor(ColorGREEN);cout<<"      nhan  ";SetColor(ColorRED);cout<<"<-";SetColor(ColorGREEN);cout<<"  hoac  ";SetColor(ColorRED);cout<<"->";SetColor(ColorGREEN);cout<<" de xem danh sach may bay      ";
		gotoxy(75,33+2);cout<<"               -------------------------------        ";
		gotoxy(75,34+2);SetColor(ColorGREEN);cout<<"  so hieu MB           Loai MB               So cho ngoi ";
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
	//	TableMayBay();
	//	HienThiTrang(tongtrang, trang, 102, 39);
	//	HuongDanButton();
	

	//	XoaManHinhThongBao1();
	//	logo(3,10);
	//	VeHCN( 0,0,166, 8,ColorWHITE);
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		gotoxy(tabx + 4, taby + 3+3);
	
		int k = 0;
	
		for (int i = 0 + trang * 8; i < 8 + trang * 8 && i < lmb.soluong; i++)
		{
			
			gotoxy(tabx + 5, 34 + 3 + k); cout<<lmb.maybay[i]->soHieuMB;
			gotoxy(tabx + 23, 34 + 3 + k); cout <<lmb.maybay[i]->loaiMB;
			gotoxy(tabx + 50, 34 + 3 + k); cout <<lmb.maybay[i]->soCho;
		
			k++;
		
			
		}
		

		

				string tmp = nhapChuoiThemCB(15,boxx + 28, boxy - 6+6);
				gotoxy(boxx + 28, boxy - 6+6); 
				
				
				if(tmp == "exit"){
					break;
				}else if(tmp == "left"){
						if(tongtrang > 1 && trang > 0)
						{
							trang--;
						
							goto Xuat;
						}else{
							
							goto Xuat;
						}
					
		
				}else if(tmp == "right"){
						if(tongtrang > 1 && trang  + 1 < tongtrang)
						{
							
							
							
							
							trang++;
							goto Xuat;
						}else{
						
							goto Xuat;
						}
					
				}
				
				strcpy(cb.soHieuMB, tmp.c_str()); 
				strcpy(cb.soHieuMB, fix_Ma(cb.soHieuMB));	
				socho = getsocho(lmb, cb.soHieuMB);
			
				if (CheckSoHieu_MB(lmb, cb.soHieuMB) != -1)
				{
					demfield++;
					gotoxy(boxx + 28, boxy - 6+6);  	cout<<"                       ";
					gotoxy(boxx + 28, boxy - 6+6); 	cout<<cb.soHieuMB;
					trung = true;
				}
				else if (strcmp(cb.soHieuMB, "\0") == 0)
				{
					gotoxy(boxx +11+ xThongBao, 32); cout<<"KHONG BO TRONG !";
					Sleep(500);  
					gotoxy(boxx+11 + xThongBao, 32 ); cout<<"                                 ";
					gotoxy(boxx + 28, boxy - 6+6);  cout<<"                     ";
				}
				else
				{
					gotoxy(boxx +11+ xThongBao, 32);cout<<"SO HIEU MAY BAY NAY KHONG CO !";
					Sleep(500);  
					gotoxy(boxx +11+ xThongBao, 32); cout<<"                                 ";
					gotoxy(boxx + 28, boxy +6- 6);  cout<<"                                 ";
				}	
			}while(trung == false);
			if (strcmp(cb.soHieuMB, "") == 0) break;
			
			// NHAP MA CHUYEN BAY
			do{
				trung = false;
				gotoxy(boxx + 28, boxy - 4+6);
				string tmp = nhapChuoi(15,boxx + 28, boxy - 4+6);

				if(tmp == "exit"){
					break;
				}
				strcpy(cb.maCB, tmp.c_str()); 
				strcpy(cb.maCB, fix_Ma(cb.maCB));
				
				if (Check_MaCB(listCB, cb.maCB) == 1)
				{
					gotoxy(boxx +11 + xThongBao, 32); cout<<"MA CHUYEN BAY NAY DA CO!";
					Sleep(1000);  
					gotoxy(boxx +11 + xThongBao, 32); cout<<"                                 ";
					gotoxy(boxx+ 28, boxy +6- 4);  cout<<"                                 ";
				}
				else if (strcmp(cb.maCB, "\0") == 0)
				{
					gotoxy(boxx+11 + xThongBao, 32); cout<<"KHONG BO TRONG!";
					Sleep(1000);  
					gotoxy(boxx+11 + xThongBao, 32); cout<<"                                 ";
					gotoxy(boxx + 28, boxy+6 - 4);  cout<<"                                 ";
				}
				else
				{
					demfield++;
					gotoxy(boxx + 28, boxy+6 - 4);  cout<<"                                 ";
					gotoxy(boxx + 28, boxy+6 - 4);cout<<cb.maCB;
					trung = true;
				}
			}while(trung == false);
			if (strcmp(cb.maCB, "") == 0) break;
			
			// NHAP NAM
			do{
				trung = false;
				gotoxy(boxx + 28, boxy - 2+6);
				char nam[10];
				string tmp = nhapSo(4,boxx + 28, boxy - 2+6);

				if(tmp == "exit"){
					break;
				}
				strcpy(nam, tmp.c_str()); 
				
				strcpy(nam, fix_Ma(nam));
				if (strcmp(nam, "\0") == 0)
				{
					gotoxy(boxx+11 + xThongBao, 32); cout<<"KHONG BO TRONG";
					Sleep(1000);  
					gotoxy(boxx+11 + xThongBao, 32); cout<<"               ";
					gotoxy(boxx + 28, boxy - 2+6);  cout<<"    ";
				}
				else
				{
					int check = check_Chuoi_Char(nam);
					if (check == 1)
					{
						int namBay = atoi(nam);
						if (namBay < 2020)
						{
							gotoxy(boxx+11 + xThongBao, 32); 	cout<<"CHI NHAN SO VA >= 2020!";
							Sleep(1000);  
							gotoxy(boxx+11 + xThongBao, 32); 	cout<<"                                 ";
							gotoxy(boxx + 28, boxy - 2+6);  	cout<<"    ";
						}
						else 
						{
							demfield++;
							cb.tgKhoiHanh.nam = namBay;
							gotoxy(boxx + 28, boxy - 2+6);  	cout<<"                                 ";
							gotoxy(boxx + 28, boxy - 2+6);	cout<<cb.tgKhoiHanh.nam;
							trung = true;
						}
					}
					else
					{
						gotoxy(boxx+11 + xThongBao, 32); cout<<"KHONG DUOC CO CHU!";
						Sleep(1000);  
						gotoxy(boxx+11 + xThongBao, 32); cout<<"                  ";
						gotoxy(boxx + 11+28, boxy - 2+6);  cout<<"    ";
					}
					
				}
		
			}while(trung == false);
			if (cb.tgKhoiHanh.nam == -1) break;
			
			// NHAP THANG
			do{
				trung = false;
				gotoxy(boxx + 28, boxy+6);
				char thang[10];
				string tmp = nhapSo(2,boxx + 28, boxy+6);

				if(tmp == "exit"){
					break;
				}
				strcpy(thang, tmp.c_str()); 
				
				strcpy(thang, fix_Ma(thang));
				if (strcmp(thang, "\0") == 0)
				{
					gotoxy(boxx + xThongBao+11, 32); cout<<"KHONG BO TRONG";
					Sleep(1000);  
					gotoxy(boxx + xThongBao+11, 32); cout<<"                                ";
					gotoxy(boxx + 28, boxy+6);  cout<<"    ";
				}
				else
				{
					int check = check_Chuoi_Char(thang);
					if (check == 1)
					{
						int thangBay = atoi(thang);
						if (thangBay <= 0 || thangBay > 12)
						{
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"THANG KHONG HOP LE ";
							Sleep(1000);  
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"                        ";
							gotoxy(boxx + 28, boxy+6);  	cout<<"    ";
						}else if(Check_thang(thangBay,cb.tgKhoiHanh.nam) == false){
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"THANG PHAI >= HIEN TAI ";
							Sleep(1000);  
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"                        ";
							gotoxy(boxx + 28, boxy+6);  	cout<<"    ";
						}
						else
						{
							demfield++;
							cb.tgKhoiHanh.thang = thangBay;
							gotoxy(boxx + 28, boxy+6);  	cout<<"    ";
							gotoxy(boxx + 28, boxy+6);	cout<<cb.tgKhoiHanh.thang;
							trung = true;
						}
					}
					else
					{
						gotoxy(boxx + xThongBao+11, 32); cout<<"KHONG DUOC CO CHU!";
						Sleep(1000);  
						gotoxy(boxx + xThongBao+11, 32); cout<<"                   ";
						gotoxy(boxx + 28, boxy+6);  cout<<"    ";
					}
				}
		
			}while(trung == false);
			if (cb.tgKhoiHanh.thang == -1) break;
			
			// NHAP NGAY
			do{
				trung = false;
				gotoxy(boxx + 28, boxy + 2+6);
				char ngay[10];
				string tmp = nhapSo(2,boxx + 28, boxy + 2+6);

				if(tmp == "exit"){
					break;
				}
				strcpy(ngay, tmp.c_str()); 
				
				strcpy(ngay, fix_Ma(ngay));
				if (strcmp(ngay, "\0") == 0)
				{
					gotoxy(boxx + xThongBao+11, 32); cout<<"KHONG BO TRONG";
					Sleep(1000);  
					gotoxy(boxx + xThongBao+11,32); cout<<"                   ";
					gotoxy(boxx + 28, boxy + 2+6);  cout<<"    ";
				}
				else
				{
					int check = check_Chuoi_Char(ngay);
					if (check == 1)
					{
						int ngayBay = atoi(ngay);
						if (ngayBay <= 0 || ngayBay > 31 || !Check_Date(cb.tgKhoiHanh.nam, cb.tgKhoiHanh.thang, ngayBay))
						{
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"NGAY KHONG HOP LE ";
							Sleep(1000);  
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"                        ";
							gotoxy(boxx + 28, boxy + 2+6);  	cout<<"    ";
						}
						else if(Check_Ngay(ngayBay,cb.tgKhoiHanh.thang,cb.tgKhoiHanh.nam)== false){
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"NGAY PHAI >= NGAY HIEN TAI ";
							Sleep(1000);  
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"                           ";
							gotoxy(boxx + 28, boxy + 2+6);  	cout<<"    ";
						}
						else 
						{
							demfield++;
							cb.tgKhoiHanh.ngay = ngayBay;
							gotoxy(boxx + 28, boxy + 2+6);  	cout<<"    ";
							gotoxy(boxx + 28, boxy + 2+6);	cout<<cb.tgKhoiHanh.ngay;
							trung = true;
						}
					}
					else
					{
						gotoxy(boxx + xThongBao+11, 32); cout<<"KHONG DUOC CO CHU";
						Sleep(1000);  
						gotoxy(boxx + xThongBao+11, 32); cout<<"                  ";
						gotoxy(boxx + 28, boxy + 2+6);  cout<<"    ";
					}
				}
		
			}while(trung == false);
			if (cb.tgKhoiHanh.ngay == -1) break;
			
			// NHAP GIO
			do{
				trung = false;
				gotoxy(boxx + 28, boxy + 4+6);
				char gio[10];
				string tmp = nhapSo(2,boxx + 28, boxy + 4+6);

				if(tmp == "exit"){
					break;
				}
				strcpy(gio, tmp.c_str()); 
				
				strcpy(gio, fix_Ma(gio));
				if (strcmp(gio, "\0") == 0)
				{
					gotoxy(boxx + xThongBao+11, 32); cout<<"KHONG BO TRONG";
					Sleep(1000);  
					gotoxy(boxx + xThongBao+11, 32); cout<<"                                ";
					gotoxy(boxx + 28, boxy + 4+6);  cout<<"    ";
				}
				else
				{
					int check = check_Chuoi_Char(gio);
					if (check == 1)
					{
						int gioBay = atoi(gio);
						if (gioBay < 0 || gioBay > 23 )
						{
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"GIO KHONG HOP LE ";
							Sleep(1000);  
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"                     ";
							gotoxy(boxx + 28, boxy + 4+6);  	cout<<"    ";
						
						}else if(CheckTrungThoiGianBay(listCB,cb.soHieuMB,gioBay,cb.tgKhoiHanh.ngay,cb.tgKhoiHanh.thang,cb.tgKhoiHanh.nam) == false){
							
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"MAY BAY CHUA SAN SANG";
							Sleep(1000);  
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"                       ";
							gotoxy(boxx + 28, boxy + 4+6);  	cout<<"    ";
						}else if(Check_Gio(gioBay,cb.tgKhoiHanh.ngay,cb.tgKhoiHanh.thang,cb.tgKhoiHanh.nam)== false ){
							
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"GIO PHAI > GIO HIEN TAI ";
							Sleep(1000);  
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"                        ";
							gotoxy(boxx + 28, boxy + 4+6);  	cout<<"    ";
							
							
						}
						else 
						{
							demfield++;
							
							cb.tgKhoiHanh.gio = gioBay;
							gotoxy(boxx + 28, boxy + 4+6);  	cout<<"    ";
							gotoxy(boxx + 28, boxy + 4+6);	cout<<cb.tgKhoiHanh.gio;
							trung = true;
						}
					}
					else
					{
						gotoxy(boxx + xThongBao+11, 32); cout<<"KHONG DUOC CO CHU!";
						Sleep(1000);  
						gotoxy(boxx + xThongBao+11, 32); cout<<"                                ";
						gotoxy(boxx + 28, boxy + 4+6);  cout<<"    ";
					}
						
				}
		
			}while(trung == false);
			if (cb.tgKhoiHanh.gio == -1) break;
			
			// NHAP PHUT
			do{
				trung = false;
				gotoxy(boxx + 28, boxy + 6+6);
				char phut[10];
				string tmp = nhapSo(2,boxx + 28, boxy + 6+6);

				if(tmp == "exit"){
					break;
				}
				strcpy(phut, tmp.c_str()); 
				
				strcpy(phut, fix_Ma(phut));
				if (strcmp(phut, "\0") == 0)
				{
					gotoxy(boxx + xThongBao+11, 32); cout<<"KHONG BO TRONG";
					Sleep(1000);  
					gotoxy(boxx + xThongBao+11, 32); cout<<"                                ";
					gotoxy(boxx + 28, boxy + 6+6);  cout<<"    ";
				}
				else
				{
					int check = check_Chuoi_Char(phut);
					if (check == 1)
					{
						int phutBay = atoi(phut);
						if (phutBay < 0 || phutBay > 59)
						{
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"PHUT KHONG HOP LE ";
							Sleep(1000);  
							gotoxy(boxx + xThongBao+11, 32); 	cout<<"                                ";
							gotoxy(boxx + 28, boxy + 6+6);  	cout<<"    ";
						}
						else 
						{
							demfield++;
							cb.tgKhoiHanh.phut = phutBay;
							gotoxy(boxx + 28, boxy + 6+6);  	cout<<"    ";
							gotoxy(boxx + 28, boxy + 6+6);	cout<<cb.tgKhoiHanh.phut;
							trung = true;
						}
					}
					else
					{
						gotoxy(boxx + xThongBao+11, 32); cout<<"KHONG DUOC CO CHU!";
						Sleep(1000);  
						gotoxy(boxx + xThongBao+11, 32); cout<<"                                ";
						gotoxy(boxx + 28, boxy + 6+6);  cout<<"    ";
					}
				}
		
			}while(trung == false);
			if (cb.tgKhoiHanh.phut == -1) break;
			
			if (!Check_ThoiGian_ChuyenBay(cb.tgKhoiHanh))
			{
				gotoxy(boxx + xThongBao+11, 32); 	cout<<"THOI GIAN CUA BAN DA QUA HAN";
				Sleep(1000);  
				gotoxy(boxx + xThongBao+11, 32); 	cout<<"                                ";
				continue;
			}
			
			// NHAP SAN BAY DEN
			do{
				trung = false;
				gotoxy(boxx + 28, boxy + 8+6);
				char sanBayDen[150];
				string tmp = nhapChuoi(30,boxx + 28, boxy + 8+6);

				if(tmp == "exit"){
					break;
				}
				strcpy(sanBayDen, tmp.c_str()); 
				
				strcpy(sanBayDen, fix_HoTen(sanBayDen));
				if (strcmp(sanBayDen, "\0") == 0)
				{
					gotoxy(boxx + xThongBao+11, 32); cout<<"KHONG BO TRONG";
					Sleep(1000);  
					gotoxy(boxx + xThongBao+11, 32); cout<<"                                ";
					gotoxy(boxx + 28, boxy + 8+6);  cout<<"    ";
				}
				else
				{
					demfield++;
					strcpy(cb.sanBayDen, sanBayDen);
					gotoxy(boxx + 28, boxy + 8+6);  	cout<<"    ";
					gotoxy(boxx + 28, boxy + 8+6);	cout<<cb.sanBayDen;
					trung = true;
				}
		
			}while(trung == false);
			if (cb.sanBayDen == 0) break;
			
			int soCho = getsocho(lmb, cb.soHieuMB);
			
			
			if (demfield == 8)
			{
				initListVe(cb.dsVe, soCho);
				InsertLast_CB(listCB, cb);
				gotoxy(boxx + xThongBao+11, 32); cout<<"DA THEM THANH CONG";
				Sleep(1500);  
				gotoxy(boxx + xThongBao+11,32); cout<<"                             ";
				demfield = 0;
			}
	}
	int a = XacNhanSaveFile();
	if(a == 1)
	{
		LuuFileChuyenBay(listCB, lmb);
	}
}
void XoaChuyenBay(SingleList_CB &lcb, ListMayBay lmb){
 	NhapMA:
 		SetBGColor(ColorBLACK);
		XoaManHinhThongBao1();
		XoaManHinhHuongDan();
		HuongDanXoaCB();
		frame_NhapMaChuyenBay(3,16);
		char maCB[15];
		gotoxy(8, 17); SetColor(ColorPURPLE); SetBGColor(ColorWHITE);
		string ma = nhapChuoi(15,8,17);
		if (ma == "exit")
			return;
		strcpy(maCB, ma.c_str());
		strcpy(maCB, fix_Ma(maCB));
		int x = Check_MaCB(lcb, maCB);
		if (x == -1)
		{
			SetColor(ColorWHITE); SetBGColor(ColorBLACK);
			gotoxy(3,19); cout<<"Khong tim thay chuyen bay nay!";
			Sleep(1000);
			gotoxy(3,19); cout<<"            	       			";
			goto NhapMA;
		}
		else{
			Node_CB *pNode = SearchCB(lcb, maCB);
			int socho = getsocho(lmb, pNode->cb.soHieuMB);
			bool co_HK = CheckHKTrongCBHayKhong(pNode->cb.dsVe, socho);
			if (co_HK){
				gotoxy(3,19); cout<<"Da co hanh khach dat ve.";
				Sleep(1500);
				gotoxy(3,19); cout<<"            			 ";
				goto NhapMA;
			}
			
			int a = XacNhanXoa();
			if(a == 1)
			{
					
				bool flag = Delete_CB_Theo_Ma(lcb, maCB);
			if (flag){
				gotoxy(3,19); cout<<"Xoa chuyen bay thanh cong!";
			//	Sleep(1000);
				gotoxy(3,19); cout<<"            				";
			}
			else
			{
				gotoxy(3,19); cout<<"CB co hanh khach chua bay.";
				Sleep(1000);
				gotoxy(3,19); cout<<"            			   ";
				goto NhapMA;
			}
				LuuFileChuyenBay(lcb, lmb);
			}
			XoaManHinhTrungTam();
			
		
		}
		
 }

int CountCB(SingleList_CB lcb)
{
	int count = 0;
	for (Node_CB *pNode = lcb.pHead; pNode != NULL; pNode=pNode->pNext){
		count++;
	}
	return count;
}

void frame_HuyCB(int x, int y);
void Danh_Sach_ChuyenBay(SingleList_CB &lcb, ListMayBay lmb)
{	
	Danhsach:
	XoaManHinhHuongDan();
	HuongDanButtonCB();
	int trang = 0, tongtrang = 0, i = 0;
	int soluong = CountCB(lcb);
	if (soluong <= 20)
	{
		trang = 0;
		tongtrang = 1;
	}
	else
	{
		tongtrang = (soluong / 21) + 1;
	}
	while(1)
	{
	Xuat:
		XoaManHinhThongBao1();
		XoaManHinhHuongDan();
		HuongDanButtonCB();	
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		logo(3,10);
		TableChuyenBay();
		HienThiTrang(tongtrang, trang, 95, 39);

		
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		
		gotoxy(tabxCB + 4, taby + 3);
		int dem = 0;
		int item = 0 + trang * 20;
		int itemtoida = 20 + trang * 20;
		
		for (Node_CB *pNode = lcb.pHead; pNode != NULL; pNode=pNode->pNext)
		{
			if (item < itemtoida && item < soluong)
			{
				int ngay = pNode->cb.tgKhoiHanh.ngay;
				int thang = pNode->cb.tgKhoiHanh.thang;
				int nam = pNode->cb.tgKhoiHanh.nam;
				int gio = pNode->cb.tgKhoiHanh.gio;
				int phut = pNode->cb.tgKhoiHanh.phut;
				
				if (Check_ThoiGian_ChuyenBay(pNode->cb.tgKhoiHanh) == false)
				 	pNode->cb.trangThai = 3;
				
				gotoxy(tabxCB + 4, taby + 3 + dem); cout <<dem+1;
				gotoxy(tabxCB + 12, taby + 3 + dem); cout<<pNode->cb.soHieuMB;
				gotoxy(tabxCB + 27, taby + 3 + dem); cout<<pNode->cb.maCB;
				gotoxy(tabxCB + 42, taby + 3 + dem); cout <<ngay<<"/"<<thang<<"/"<<nam;
				gotoxy(tabxCB + 60, taby + 3 + dem); cout<<gio<<":"<<phut;
				gotoxy(tabxCB + 73, taby + 3 + dem); cout <<pNode->cb.sanBayDen;
				gotoxy(tabxCB + 88, taby + 3 + dem); cout <<pNode->cb.trangThai;
				dem++;
				item++;
			}
		
		}
		
		gotoxy(96-7, 38);
		cout << "[<-] Tro lai | Tiep Theo [->]"; 
		
		int c = 0;
		do{
			c = getch();
		}while(c != LEFT && c != RIGHT && c!= ESC && c != F1 && c != F2 && c != F3 && c != F4);
		if (c == ESC)
		{

			XoaManHinhTrungTam();
			XoaManHinhHuongDan();
		
			
			break;
		}
		else if (c == LEFT)
		{
			if(tongtrang > 1 && trang > 0)
			{
				trang--;
				goto Xuat;
			}
		}
		else if (c == RIGHT)
		{
			if(tongtrang > 1 && trang  + 1 < tongtrang)
			{
				trang++;
				goto Xuat;
			}
		}
		else if (c == F1)
		{

			NhapChuyenBay(lmb, lcb);
			goto Danhsach;
		}
		else if (c == F2)
		{
		
			XoaChuyenBay(lcb,lmb);
			XoaManHinhTrungTam();
			XoaManHinhHuongDan();
			goto Xuat;
		}
		else if (c == F3)
		{
		
			SuaChuyenBay(lcb,lmb);
			XoaManHinhTrungTam();
			XoaManHinhHuongDan();

			goto Xuat;
		}
		else if (c == F4)
		{
		//	Sleep(500);
			
			NhapLai:
				SetBGColor(ColorBLACK);
			XoaManHinhThongBao1();
				XoaManHinhHuongDan();
				textcolor(MauNenHuongDan);
				gotoxy(10,12);
				cout << "< HUY CHUYEN BAY >";
				frame_HuyCB(3,16);
				char macb[15];
				gotoxy(8,17);
			//	frame_NhapMaChuyenBay(3,16);
				
				SetBGColor(ColorWHITE); SetColor(ColorBLACK);
				string ma = nhapChuoi(15,8,17);
				if (ma == "exit") {
				XoaManHinhTrungTam();
				XoaManHinhThongBao1();
				XoaManHinhHuongDan();
				
				break;
				}
				
				strcpy(macb, ma.c_str());
				strcpy(macb, fix_Ma(macb));
				if (strcmp(macb, "\0") == 0)
				{
				//	SetColor(ColorBLACK); SetBGColor(ColorWHITE);
					gotoxy(8,19); cout<<"Khong bo trong!";
					Sleep(1000);
					gotoxy(8,19); cout<<"               ";
//					gotoxy(47,8); SetBGColor(ColorWHITE);cout<<"                     ";
					goto NhapLai;
				}
				else
				{
					Node_CB *pNode = SearchCB(lcb, macb);
					if (pNode != NULL)
					{
						if (pNode->cb.trangThai == 3){
							gotoxy(3,19); cout<<"Chuyen bay nay da hoan tat !";
							Sleep(1500);
							gotoxy(3,19); cout<<"                             ";
							gotoxy(3,17); cout<<"                     ";
							goto NhapLai;
						}
						else{
							// Kiem tra neu co HK thi` ko the huy chuyen
							int socho = getsocho(lmb, pNode->cb.soHieuMB);
							bool co_HK = CheckHKTrongCBHayKhong(pNode->cb.dsVe, socho);
							if (co_HK){
								gotoxy(8,19); cout<<"Da co hanh khach dat ve.";
								Sleep(1500);
								gotoxy(8,19); cout<<"                        ";
								gotoxy(3,17); cout<<"                 ";
								goto NhapLai;
							}
							else{
								pNode->cb.trangThai = 0;
								gotoxy(8,19); cout<<"Huy chuyen thanh cong!";
								Sleep(1000);
								gotoxy(3,17); cout<<"                        ";
									int a = XacNhanSaveFile();
								if(a == 1)
								{
									LuuFileChuyenBay(lcb, lmb);
								}
								goto Xuat;
							}
						}
							
					}
					else
					{
						gotoxy(8,19); cout<<"Chuyen bay hien ko co!";
						Sleep(1000);
						gotoxy(8,19); cout<<"                      ";
						gotoxy(3,17); cout<<"                     ";
						goto NhapLai;
					}
				}	
		}
	}	
}







bool Check_ThoiGian_NoiDen(ChuyenBay cb, ThoiGian tg, char noiDen[])
{
	ThoiGian thoiGian = cb.tgKhoiHanh;
	if (thoiGian.nam == tg.nam && thoiGian.thang == tg.thang && thoiGian.ngay == tg.ngay && strcmp(cb.sanBayDen, noiDen) == 0)
		return true;
	return false;
}

int soLuong_CB_TG_ND(SingleList_CB lcb, ThoiGian tg, char noiden[])
{
	int count = 0;
	for(Node_CB *pNodeCB = lcb.pHead; pNodeCB != NULL; pNodeCB=pNodeCB->pNext)
	{
		if (Check_ThoiGian_NoiDen(pNodeCB->cb, tg, noiden) == true)
		{
			count++;
		}
	}
	return count;
}

void frame_NhapNgay_NoiDen(int x, int y);
void Danh_Sach_ChuyenBay_Trong_Ngay(SingleList_CB lcb, ListMayBay lmb)
{	
//		int xThongBao = 40, yThongBao = 17;
	NhapLai:
		int trang = 0, tongtrang = 0;
		ThoiGian tg;
		tg.nam = -1;
		tg.thang = -1;
		tg.ngay = -1;
		tg.gio = -1;
		tg.phut = -1;
		char noiden[150];
		strcpy(noiden,"");
		
		
	while(true)
	{
	//	system("cls");
		SetBGColor(0);
		SetColor(255);
	    VeHCN(4,25,20+7+5,10-4,10);
		frame_NhapNgay_NoiDen(5,26);
	
		int demfield = 0;
		
		// NAM
		NhapNAM:
			char nam_input[10];
			gotoxy(18-3,27);
			
			string tmp = nhapSo(4,18-3,27);
			
			if (tmp == "exit") return;
			strcpy(nam_input, tmp.c_str());
			strcpy(nam_input, fix_Ma(nam_input)); // chua xet TH rong, ko co ma CB
	
			if (strcmp(nam_input, "\0") == 0)
			{
				gotoxy(8,35); cout<<"Khong bo trong";
				Sleep(1000);
				gotoxy(8,35); cout<<"              ";
				goto NhapNAM;
			}
			else 
			{
				int check = check_Chuoi_Char(nam_input);
				if (check == 1)
				{
					int nam_info = atoi(nam_input);
					if (nam_info < 2019)
					{
						gotoxy(8,35); cout <<"NAM >= 2019!";
						Sleep(1500);
						gotoxy(8,35); cout <<"            ";
						gotoxy(18-3,27); cout << "    ";
						goto NhapNAM;
					}else
					{
						demfield++;
						tg.nam = nam_info;
						gotoxy(18-3, 27);  cout<<"    ";
						gotoxy(18-3, 27);  cout<<tg.nam;
						goto NhapTHANG;
					}
				}
				else
				{
					gotoxy(8,35); cout <<"Khong duoc co chu!";
					Sleep(1500);
					gotoxy(8,35); cout <<"                  ";
					gotoxy(18-3,27); cout << "    ";
					goto NhapNAM;
				}
				
				
			}
		
		// THANG
		NhapTHANG:
			char thang_input[10];
			gotoxy(18-3,28);
			tmp = "";
			tmp = nhapSo(2,18-3,28);
			
			if (tmp == "exit") return;
			strcpy(thang_input, tmp.c_str());
			strcpy(thang_input, fix_Ma(thang_input)); // chua xet TH rong, ko co ma CB
	
			if (strcmp(thang_input, "\0") == 0)
			{
				gotoxy(8,35); cout <<"Khong bo trong";
				Sleep(1500);
				gotoxy(8,35); cout <<"              ";
				gotoxy(18-3,28); cout <<"    ";
				goto NhapTHANG;
			}
			else 
			{
				int check = check_Chuoi_Char(thang_input);
				if (check == 1)
				{
					int thang_info = atoi(thang_input);
					if (thang_info <= 0 || thang_info > 12)
					{
						gotoxy(8,35); cout <<"THANG KHONG HOP LE";
						Sleep(1500);
						gotoxy(8,35); cout <<"                  ";
						gotoxy(18-3,28); cout <<"    ";
						goto NhapTHANG;
					}else
					{
						demfield++;
						tg.thang = thang_info;
						gotoxy(18-3, 28);   cout<<"    ";
						gotoxy(18-3, 28);   cout<<tg.thang;
						goto NhapNGAY;
					}
				}
				else
				{
					gotoxy(8,35); cout <<"Khong duoc co chu!";
					Sleep(1500);
					gotoxy(8,35); cout <<"                  ";
					gotoxy(18-3,28); cout <<"    ";
					goto NhapTHANG;
				}
				
			}
		
		
		// NGAY
		NhapNGAY:
			char ngay_input[10];
			gotoxy(18-3,29);
			tmp = "";
			tmp = nhapSo(2,18-3,29);
			
			if (tmp == "exit") return;
			strcpy(ngay_input, tmp.c_str());
			strcpy(ngay_input, fix_Ma(ngay_input)); // chua xet TH rong, ko co ma CB
	
			if (strcmp(ngay_input, "\0") == 0)
			{
				gotoxy(8,35); cout <<"Khong bo trong";
				Sleep(1500);
				gotoxy(8,35); cout <<"              ";
				gotoxy(18-3,29); cout <<"    ";
				goto NhapNGAY;
			}
			else 
			{
				int check = check_Chuoi_Char(ngay_input);
				if (check == 1)
				{
					int ngay_info = atoi(ngay_input);
					if (ngay_info <= 0 || ngay_info > 31 || !Check_Date(tg.nam,tg.thang,ngay_info))
					{
						gotoxy(8,35); cout <<"NGAY KHONG HOP LE";
						Sleep(1500);
						gotoxy(8,35); cout <<"                 ";
						gotoxy(18-3,29); cout <<"    ";
						goto NhapNGAY;
					}else
					{
						demfield++;
						tg.ngay = ngay_info;
						gotoxy(18-3, 29);  	cout<<"    ";
						gotoxy(18-3, 29);     cout<<tg.ngay;
						goto NhapNOIDEN;
					}
				}
				else
				{
					gotoxy(8,35); cout <<"Khong duoc co chu!";
					Sleep(1500);
					gotoxy(8,35); cout <<"                  ";
					gotoxy(18-3,29); cout <<"    ";
					goto NhapNGAY;
				}
			}
		
		
		// NOI DEN
		NhapNOIDEN:
			gotoxy(18-3,30);
			tmp = "";
			tmp = nhapChuoi(16,18-3,30);
			if(tmp == "exit"){
				return;
			}
			strcpy(noiden, tmp.c_str()); 
			strcpy(noiden, fix_HoTen(noiden));
			
			if (strcmp(noiden, "\0") == 0)
			{
				gotoxy(8,35); cout<<"KHONG BO TRONG!";
				Sleep(1000);  
				gotoxy(8,35); cout<<"               ";
				gotoxy(18-3,30); cout<<"                ";
				goto NhapNOIDEN;
			}
			else if (Check_NoiDen(lcb, noiden) == -1)
			{
				gotoxy(8,35); cout<<"NOI NAY CHUA CO CHUYEN NAO!";
				Sleep(1000);  
				gotoxy(8,35); cout<<"                           ";
				gotoxy(18-3,30); cout<<"                   ";
				goto NhapNOIDEN;
			}
			else 
			{
				demfield++;
				gotoxy(18-3,30);  cout<<"                ";
				gotoxy(18-3,30); cout<<noiden;
			}
		

		
		
		
		if (demfield == 4){

			
			break;
		}			
	}
	
	
	int soluong = soLuong_CB_TG_ND(lcb,tg,noiden);
	if (soluong <= 20)
	{
		trang = 0;
		tongtrang = 1;
	}
	else
	{
		tongtrang = (soluong / 21) + 1;
	}

	
	
	
	while(true)
	{
		Xuat:
			XoaManHinhTrungTam();
			TableChuyenBay();
			//gotoxy(66,2); cout<<"THEO NGAY "<<tg.ngay<<"/"<<tg.thang<<"/"<<tg.nam;
		//	gotoxy(58,3); cout<<"NOI DEN: "<<noiden;
			HienThiTrang(tongtrang, trang, 95, 40);
			SetColor(ColorBLACK);
			ButtonESC(ColorDARKWHITE);
			SetColor(ColorWHITE); SetBGColor(ColorBLACK);
			gotoxy(tabx + 4, taby + 3);
			int dem = 0;
			int item = 0 + trang * 20;
			int itemtoida = 20 + trang * 20;
			int checkpoint = 0;
			for(Node_CB *pNode = lcb.pHead ; pNode != NULL; pNode=pNode->pNext)
			{
				if (item < itemtoida && item < soluong)
				{
					if (Check_ThoiGian_NoiDen(pNode->cb, tg, noiden) == true)
					{
						checkpoint = 1;
						int ngay = pNode->cb.tgKhoiHanh.ngay;
						int thang = pNode->cb.tgKhoiHanh.thang;
						int nam = pNode->cb.tgKhoiHanh.nam;
						int gio = pNode->cb.tgKhoiHanh.gio;
						int phut = pNode->cb.tgKhoiHanh.phut;
						
						
						gotoxy(tabxCB + 4, taby + 3 + dem); cout <<dem+1;
						gotoxy(tabxCB + 12, taby + 3 + dem); cout<<pNode->cb.soHieuMB;
						gotoxy(tabxCB + 27, taby + 3 + dem); cout<<pNode->cb.maCB;
						gotoxy(tabxCB + 42, taby + 3 + dem); cout <<ngay<<"/"<<thang<<"/"<<nam;
						gotoxy(tabxCB + 60, taby + 3 + dem); cout<<gio<<":"<<phut;
						gotoxy(tabxCB + 73, taby + 3 + dem); cout <<pNode->cb.sanBayDen;
						gotoxy(tabxCB + 88, taby + 3 + dem); cout <<pNode->cb.trangThai;
						dem++;
						item++;
					}
				}
			}
			if(checkpoint == 0){
				XoaManHinhTrungTam();
				gotoxy(96-7, 39);
				cout << "KHONG TIM THAY DU LIEU"; 
				Sleep(1000);
				break;
				
			}
		gotoxy(96-7, 39);
		cout << "[<-] Tro lai | Tiep Theo [->]"; 
		
		int c = 0;
		do{
			c = getch();
		}while(c != LEFT && c != RIGHT && c!= ESC);
		if (c == ESC)
		{
			ButtonESC(1);
			Sleep(500);
			break;
		}
		else if (c == LEFT)
		{
			if(tongtrang > 1 && trang > 0)
			{
				trang--;
				goto Xuat;
			}
		}
		else if (c == RIGHT)
		{
			if(tongtrang > 1 && trang  + 1 < tongtrang)
			{
				trang++;
				goto Xuat;
			}
		}
	}	
}


void Danh_Sach_HK_Trong_CB(SingleList_CB lcb, ListMayBay lmb)
{
	

	int trang = 0, tongtrang = 0;
	char maCB[15];
	strcpy(maCB, "");
	Node_CB *pNodeCB = NULL;
	bool flag = false;
	while(flag == false)
	{
		NhapLai:
	
		Box_DS_HK_Trong_CB();
		

		gotoxy(20,22);
		string ma = nhapChuoi(15,20,22);
		if (ma == "exit") break;
		strcpy(maCB, ma.c_str());
		strcpy(maCB, fix_Ma(maCB)); // chua xet TH rong, ko co ma CB
		gotoxy(20,22); cout<<"            ";
		gotoxy(20,22); cout<<maCB;
		if (strcmp(maCB, "\0") == 0)
		{
			// 4 30
			gotoxy(4,30); cout <<"     Khong bo trong";
			Sleep(500);
			gotoxy(4,30); cout <<"	                   ";
			gotoxy(20,22);cout <<"					  ";
		
			goto NhapLai;
		}
		int x = Check_MaCB(lcb, maCB);
		if (x == -1){
			gotoxy(4,30); cout <<"   Ma CB khong ton tai!";
			Sleep(500);
			gotoxy(4,30); cout <<"                        ";
			gotoxy(20,22);cout <<"                    ";
		
			goto NhapLai;
		}else if (x == 1){
			pNodeCB = TimKiem_CB(lcb, maCB);
			flag = true;
		}
		
		gotoxy(8,26); cout<<pNodeCB->cb.tgKhoiHanh.ngay;
		gotoxy(11,26); cout<<pNodeCB->cb.tgKhoiHanh.thang;
		gotoxy(14,26); cout<<pNodeCB->cb.tgKhoiHanh.nam;
		gotoxy(11,27); cout<<pNodeCB->cb.tgKhoiHanh.gio;
		gotoxy(14,27); cout<<pNodeCB->cb.tgKhoiHanh.phut;
		gotoxy(17,28); cout<<pNodeCB->cb.sanBayDen;
		
		if (pNodeCB->cb.dsVe.n <= 20)
		{
			trang = 0;
			tongtrang = 1;
		}
		else
		{
			tongtrang = (pNodeCB->cb.dsVe.n / 21) + 1;
		}
	}
	if (strcmp(maCB, "")==0) return;
	
	while(1)
	{
	Xuat:	
	//	system("cls");
		Box_DS_HK_Trong_CB();
	//	gotoxy(80,2); cout<<maCB;
		gotoxy(8,26); cout<<pNodeCB->cb.tgKhoiHanh.ngay;
		gotoxy(11,26); cout<<pNodeCB->cb.tgKhoiHanh.thang;
		gotoxy(14,26); cout<<pNodeCB->cb.tgKhoiHanh.nam;
		gotoxy(11,27); cout<<pNodeCB->cb.tgKhoiHanh.gio;
		gotoxy(14,27); cout<<pNodeCB->cb.tgKhoiHanh.phut;
		gotoxy(17,28); cout<<pNodeCB->cb.sanBayDen;
		HienThiTrang(tongtrang, trang, 105, 38);
		SetColor(ColorBLACK);
	//	ButtonESC(ColorDARKWHITE);
		
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		gotoxy(tabx + 4, taby + 3);
		int socho = getsocho(lmb, pNodeCB->cb.soHieuMB);
		int dem = 0;
		if(pNodeCB->cb.dsVe.n < 20 + trang * 20){
			for (int i = 0 + trang * 20 ; i < socho; i++)
			{
				if (pNodeCB->cb.dsVe.ve[i] != ""){
				char cmnd[16];
				strcpy(cmnd,"");
				strcpy(cmnd,pNodeCB->cb.dsVe.ve[i].c_str());
				AVLTree pHK = SearchHK(tree, cmnd);
				char hoten[150]; 
				strcpy(hoten,"");
				strcat(hoten, pHK->hanhkhach.ho );
				strcat(hoten, " ");
				strcat(hoten, pHK->hanhkhach.ten);
				
				gotoxy(tabx + 4, taby + 3 + dem); 	cout<<dem+1;
				gotoxy(tabx + 14, taby + 3 + dem); 	cout<<i+1;
				gotoxy(tabx + 25, taby + 3 + dem); 	cout<<pNodeCB->cb.dsVe.ve[i];
				gotoxy(tabx + 47, taby + 3 + dem); cout<<hoten;
				gotoxy(tabx + 75, taby + 3 + dem); cout<<pHK->hanhkhach.phai;
				dem++;
				}
			
			}
				
		}
		else
		for (int i = 0 + trang * 20 ; i < 20 + trang * 20 && i < socho; i++)
		{
			if (pNodeCB->cb.dsVe.ve[i] != ""){
				char cmnd[16];
				strcpy(cmnd,"");
				strcpy(cmnd,pNodeCB->cb.dsVe.ve[i].c_str());
				AVLTree pHK = SearchHK(tree, cmnd);
				char hoten[150]; 
				strcpy(hoten,"");
				strcat(hoten, pHK->hanhkhach.ho );
				strcat(hoten, " ");
				strcat(hoten, pHK->hanhkhach.ten);
				
				gotoxy(tabx + 4, taby + 3 + dem); 	cout<<dem+1;
				gotoxy(tabx + 14, taby + 3 + dem); 	cout<<i+1;
				gotoxy(tabx + 25, taby + 3 + dem); 	cout<<pNodeCB->cb.dsVe.ve[i];
				gotoxy(tabx + 47, taby + 3 + dem); cout<<hoten;
				gotoxy(tabx + 75, taby + 3 + dem); cout<<pHK->hanhkhach.phai;
				dem++;
			}
			
		}
		gotoxy(102, 37);
		cout << "[<-] Tro lai | Tiep Theo [->]"; 
		
		int c = 0;
		do{
			c = getch();
		}while(c != LEFT && c != RIGHT && c != ESC);
		if (c == LEFT)
		{
			if(tongtrang > 1 && trang > 0)
			{
				trang--;
				goto Xuat;
			}
		}
		else if (c == RIGHT)
		{
			if(tongtrang > 1 && trang  + 1 < tongtrang)
			{
				trang++;
				goto Xuat;
			}
		}
		else if (c == ESC)
		{
			XoaManHinhTrungTam();
			XoaManHinhThongBao2();
			break;
		}
	}	
}





void frame_HuyCB(int x, int y)
{
	gotoxy(x, y); SetBGColor(ColorBLACK); SetColor(ColorWHITE);	cout << "      NHAP MA CB MUON HUY";
	gotoxy(x, y + 1); SetBGColor(ColorBLACK);		cout << "     ";
	gotoxy(x + 5, y + 1);  SetBGColor(ColorWHITE); 	cout << "                       ";
	gotoxy(x + 27, y + 1); SetBGColor(ColorBLACK); 	cout << "     ";
	gotoxy(x, y + 2); SetBGColor(ColorBLACK);		cout << "                                ";
	SetBGColor(ColorBLACK); SetColor(ColorBLACK);
}


void frame_NhapNgay_NoiDen(int x, int y)
{
	gotoxy(x, y);	cout << "    NHAP VAO THOI GIAN    ";
	gotoxy(x, y + 1); cout << "  Nam    :";
	gotoxy(x, y + 2); cout << "  Thang  :";
	gotoxy(x, y + 3); cout << "  Ngay   :";
	gotoxy(x, y + 4); cout << "  Noi den: ";
	
	

}


void Danh_Sach_Ve_Trong_CB(SingleList_CB lcb, ListMayBay lmb)
{
	int tmp;
	frame_NhapMaChuyenBay(3,28);
	ChuyenBay cb;
	int trang = 0, tongtrang = 0, socho = 0;
	NhapMACB:
		gotoxy(8,29); SetColor(ColorBLACK); SetBGColor(ColorWHITE); 	
		char maCB[15];
		string macb = nhapChuoi(15,8,29);
		if (macb == "exit") return; // ra Menu
		strcpy(maCB, macb.c_str());
		strcpy(maCB, fix_Ma(maCB));
		if (strcmp(maCB, "\0") == 0){
			gotoxy(3, 31); SetColor(ColorWHITE); SetBGColor(ColorBLACK);  cout<<"Khong bo trong";
			Sleep(1000);
			gotoxy(3, 31); cout<<"                       ";
			gotoxy(8,29); SetBGColor(ColorWHITE);cout<<"                     ";
			goto NhapMACB;
		}else{
			int x = Check_MaCB(lcb, maCB);
			if (x == 1)
			{
				
				cb = TimKiem_CB(lcb, maCB)->cb;
				goto DanhSachVeTrong;
			}else{
				gotoxy(3, 31); SetColor(ColorWHITE); SetBGColor(ColorBLACK);  cout<<"Khong ton tai ma nay!";
				Sleep(1000);
				gotoxy(3, 31); cout<<"                       ";
				gotoxy(8,29); SetBGColor(ColorWHITE);cout<<"                     ";
				goto NhapMACB;
			}
		}
	DanhSachVeTrong:
//		gotoxy(1,1); cout<<cb.dsVe.n;
//		system("pause");
		XoaManHinhTrungTam();
		SetBGColor(ColorBLACK);
		SetColor(ColorWHITE);
		socho = getsocho(lmb, cb.soHieuMB);
		int vetrong = socho - cb.dsVe.n;	
		if (vetrong <= 20)
		{
			trang = 0;
			tongtrang = 1;
		}
		else
		{
			tongtrang = (vetrong / 21) + 1;
		}
		while(1)
		{
		Xuat:	
//		//	system("cls");

			XoaManHinhTrungTam();
			Box_DS_Ve_Trong_Trong_CB();
			HienThiTrang(tongtrang, trang, tabx+20+15+2, 35);
			SetColor(ColorBLACK);
		//	ButtonESC(ColorDARKWHITE);
			SetColor(9); SetBGColor(ColorWHITE);
			gotoxy(8,29); cout<<cb.maCB;
			SetColor(ColorWHITE); SetBGColor(ColorBLACK);
			gotoxy(tabx + 30, taby + 3);
 	
 			
 			// Neu ve trong < 20 ve
			int dem = 0;
			if (tongtrang == 1){
				for (int i = 0 + trang * 20; i < 20 + tongtrang * 20 && i < socho; i++) 
				{
					if (cb.dsVe.ve[i] == ""){
						gotoxy(tabx + 30, taby + 3 + dem); 	cout<<dem+1;
						gotoxy(tabx + 56, taby + 3 + dem); 	cout<<i+1;
						dem++;
					}	
				}
			}	
			else if (tongtrang > 1) // Neu ve trong > 20 ve
			{			
				for (int i = 0 + trang * 20; i < 20 + trang * 20 && i < socho; i++) 
				{
					if (cb.dsVe.ve[i] == ""){
						gotoxy(tabx + 40, taby + 3 + dem); 	cout<<"Ve so "<<i+1;
						dem++;
					}	
				}

				
			}
			
			
			
			int cot = 42+15, dong = 12+2;
												
												for (int i = 0; i < socho; i++) {
													if (cb.dsVe.ve[i] == "") {
													SetColor(ColorWHITE);
													SetBGColor(ColorGREEN);
													gotoxy(cot, dong); cout << i+1;
													cot = cot + 5;
												}
												else if (cb.dsVe.ve[i] != "") {
													SetColor(ColorWHITE);
													SetBGColor(ColorRED);
													gotoxy(cot, dong); cout << i+1;
													cot = cot + 5;
												}
												if (cot % (42+15+ 40 )== 0) {
													dong = dong + 2;
													cot = 42+15;
													
												}
												tmp = dong;
												}
												
												SetColor(ColorWHITE);
												SetBGColor(ColorBLACK);
												VeHCN( 42+13,13,(80+20-6)/2 - 3-4, tmp-13+1,255);
			
			
			
			
			
			
			int c = 0;
			do{
				c = getch();
			}while(c != LEFT && c != RIGHT && c != ESC);
			 if (c == LEFT)
			{
				if(tongtrang > 1 && trang > 0)
				{
					trang--;
					
					goto Xuat;
				}
			}
			else if (c == RIGHT)
			{
				if(tongtrang > 1 && trang  + 1 < tongtrang)
				{
					trang++;
					
					goto Xuat;
				}
			}
			else if (c == ESC)
			{
				break;
			}
		}	
}

void HoanViSHSL(int &x,int &y, string &n, string &m)
{
	int temp=x;
	x=y;
	y=temp;
	
	string tmp = n;
	n = m;
	m = tmp;
}


void SapXepGiamDanBangThuatToanQuickSort(int a[],string b[],int left,int right)
{
	int i,j,x;
	if(left>=right)
	{
		return;
	}
	x=a[(left+right)/2]; // Ch?n ph?n t? gi?a làm giá tr? m?c .
	i=left;
	j=right;
	while(i<j)
	{
		while(a[i]>x) // ? dây là s?p gi?m d?n
		{
			i++;
		}
		while(a[j]<x) // ? dây là s?p gi?m d?n
		{
			j--;
		}
		if(i<=j)
		{
			HoanViSHSL(a[i],a[j],b[i],b[j]);
			i++;
			j--;
		}
	}
	SapXepGiamDanBangThuatToanQuickSort(a,b,left,j);
	SapXepGiamDanBangThuatToanQuickSort(a,b,i,right);
}









void Danh_Sach_Thong_Ke_So_Luot_Bay(SingleList_CB lcb, ListMayBay lmb)
{
	gotoxy(1,14);SetBGColor(12);SetColor(255);cout<<" 5. THONG KE                           ";

	int trang = 0, tongtrang = 0;
	if (lmb.soluong <= 20)
	{
		trang = 0;
		tongtrang = 1;
	}
	else
	{
		tongtrang = (lmb.soluong / 21) + 1;
	}
	string sh[lmb.soluong]; // mang chua so Hieu
	int soluot[lmb.soluong]; // mang chua so luot
	int index = 0;
	
	for(int i = 0; i < lmb.soluong; i++)
	{
		sh[index] = string(lmb.maybay[i]->soHieuMB);
		soluot[index] = Dem(lcb,lmb.maybay[i]->soHieuMB);
		index++;
	}
//	
//	for (int i = 0; i < lmb.soluong-1; i++){
//		for (int j = lmb.soluong - 1; j > i; j--){
//			if (soluot[j-1] < soluot[j]){
//				int m = soluot[j-1];
//				string n = sh[j-1];
//				
//				soluot[j-1] = soluot[j];
//				sh[j-1] = sh[j];
//				
//				soluot[j] = m;
//				sh[j] = n;
//			}
//		}
//	}
	SapXepGiamDanBangThuatToanQuickSort(soluot,sh,0,lmb.soluong-1);
	while(1)
	{
		Xuat:
			
			XoaManHinhTrungTam();
			SetColor(ColorWHITE);
			SetBGColor(ColorBLACK);
			Box_DS_Thong_Ke_So_Luot_Bay();
			HienThiTrang(tongtrang, trang, tabx+20+15+2-20, 35);
			SetColor(ColorBLACK);
		//	ButtonESC(ColorDARKWHITE);
			SetColor(ColorWHITE); SetBGColor(ColorBLACK);
			
			gotoxy(tabx + 30-20, taby + 3);
			int dem = 0;
 			for (int i = 0 + trang * 20; i < 20 + trang * 20 && i < lmb.soluong; i++) 
			{
				gotoxy(tabx + 30-20, taby + 3 + dem); cout<<sh[i];
				gotoxy(tabx + 56-20, taby + 3 + dem); cout<<soluot[i];
				dem++;
			}
			
		
			
			int c = 0;
			do{
				c = getch();
			}while(c != LEFT && c != RIGHT && c != ESC);
			 if (c == LEFT)
			{
				if(tongtrang > 1 && trang > 0)
				{
					trang--;
					goto Xuat;
				}
			}
			else if (c == RIGHT)
			{
				if(tongtrang > 1 && trang  + 1 < tongtrang)
				{
					trang++;
					goto Xuat;
				}
			}
			else if (c == ESC)
			{
				XoaManHinhTrungTam();
				
				break;
			}
			
	}
}




int NhapHanhKhachDatVe(AVLTree &tree, char cmnd[])
{
	int  x = 28;
	int demfield = 0;

	HanhKhach hk;
	strcpy(hk.cmnd,  cmnd);
	strcpy(hk.ho,  "");
	strcpy(hk.ten,  "");
	strcpy(hk.phai,  "");
	
	
	bool trung;
	// NHAP CMND
//	do{
//		trung = false;
//		gotoxy(15, 31);  cout<<"                  ";
//		gotoxy(15,31);
//		string tmp = nhapChuoi(9,15, 31);
//		if(tmp == "exit"){
//			break;
//		}
//		strcpy(hk.cmnd, tmp.c_str());
//		strcpy(hk.cmnd, fix_Ma(hk.cmnd));
//		if (CheckCMNDIsExisted(tree, hk.cmnd) == 1)
//		{
//			gotoxy(15, 43); cout<<"CMND TRUNG!";
//			Sleep(1000);  
//			gotoxy(15, 43); cout<<"             ";
//			gotoxy(15, 31);  cout<<"                   ";
//		}
//		else if (strcmp(hk.cmnd, "\0") == 0)
//		{
//			gotoxy(15, 43); cout<<"KHONG BO TRONG !";
//			Sleep(1000);  
//			gotoxy(15, 43); cout<<"                  ";
//			gotoxy(15, 31);  cout<<"                     ";
//		}
//		else
//		{
//			int check = check_Chuoi_Char(hk.cmnd);
//			if (check == 1)
//			{
//				demfield++;
//				gotoxy(15, 43);  cout<<"                        ";
//				gotoxy(15,31); cout<<hk.cmnd;
//				trung = true;
//			}
//			else
//			{
//				gotoxy(15, 43); cout<<"CMND KHONG CHUA CHU !";
//				Sleep(1000);  
//				gotoxy(15, 43); cout<<"                      ";
//				gotoxy(15, 31);  cout<<"                      ";
//			}
//		}
//	}while(trung == false);
//	if (strcmp(hk.cmnd, "") == 0) break;
	gotoxy(15,31); cout<<hk.cmnd;
	// NHAP HO
	do{
		trung = false;
		gotoxy(15, 34);
		string tmp = nhapChuoiHo(10,15, 34);
		if(tmp == "exit"){
			break;
		}
		strcpy(hk.ho, tmp.c_str());
		strcpy(hk.ho, fix_HoTen(hk.ho));
		
		if (strcmp(hk.ho, "\0") == 0)
		{
			gotoxy(15, 43); cout<<"KHONG BO TRONG!";
			Sleep(1000);  
			gotoxy(15, 43); cout<<"                ";
			gotoxy(15, 34);  cout<<"               ";
		}
		else
		{
			demfield++;
			gotoxy(15, 34);  cout<<"                 ";
			gotoxy(15, 34);cout<<hk.ho;
			trung = true;
		}
	}while(trung == false);
//	if (strcmp(hk.ho, "") == 0) break;
	
	// NHAP TEN
	do{
		trung = false;
		gotoxy(15, 37);
		string tmp = nhapChuoiTen(20,15, 37);
		if(tmp == "exit"){
			break;
		}
		strcpy(hk.ten, tmp.c_str());
		strcpy(hk.ten, fix_Ten(hk.ten));
		
		if (strcmp(hk.ten, "\0") == 0)
		{
			gotoxy(15, 43); cout<<"KHONG BO TRONG!";
			Sleep(1000);  
			gotoxy(15, 43); cout<<"                   ";
			gotoxy(15, 37);  cout<<"                  ";
		}
		else
		{
			demfield++;
			gotoxy(15, 37);  cout<<"                 ";
			gotoxy(15, 37);cout<<hk.ten;
			trung = true;
		}
	}while(trung == false);
	//if (strcmp(hk.ten, "") == 0) break;
	
	// NHAP PHAI (NAM/NU)
	do{
		trung = false;
		gotoxy(15, 40);
		char phai[10];
		string tmp = nhapChuoi(5,15, 40);
		if(tmp == "exit"){
			break;
		}
		char temp[10];
		strcpy(temp, tmp.c_str());
		strcpy(phai, fix_GioiTinh(temp));
		if (strcmp(phai, "\0") == 0)
		{
			gotoxy(15, 43); cout<<"KHONG BO TRONG!";
			Sleep(1000);  
			gotoxy(15, 43); cout<<"                 ";
			gotoxy(15, 40);  cout<<"               ";
		}
		else if ((strncmp(phai, "nam", 3) == 0 ) || (strncmp(phai, "nu", 2) == 0) )
		{
			demfield++;
			strcpy(hk.phai, phai);
			gotoxy(15, 43);  cout<<"                 ";
			gotoxy(15, 40);cout<<hk.phai;
			trung = true;
		}
		else
		{
			gotoxy(15, 43); cout<<"KHONG DUNG YEU CAU!";
			Sleep(1000);  
			gotoxy(15, 43); cout<<"                    ";
			gotoxy(15, 40);  cout<<"                    ";
			
		}
	}while(trung == false);
//	if (strcmp(hk.phai, "") == 0) break;
	
	if (demfield == 3 && XacNhanSaveFile())
	{
	//	gotoxy(15, 43); cout<<"DA THEM THANH CONG";
			XoaManHinhThongBao1();
			InsertHKToTree(tree, hk);
			LuuFileHKKoDeQuy(tree);
			return 1;
	//	Sleep(1500);  
	//	gotoxy(15, 43); cout<<"                   ";
			demfield = 0;
		
	}
	

	//XoaManHinhThongBao2();
	return 0;
	
}























bool Check_ListVe_Full(ChuyenBay cb,int socho) {
	int dem = 0;
	for (int i = 0; i < socho; i++) {
		if (cb.dsVe.ve[i] != ""){
			dem++;
		}
	}
	if (dem == socho) {
		return true;
	}
	else {
		return false;
	}
}

//==== DAT VE
bool Check_Trung_Ve_Mot_Nguoi_Mot_Ngay(SingleList_CB &listCB,int Ngay,int Thang,int Nam, string cmnd){
	

	
		for (Node_CB *pNode = listCB.pHead; pNode != NULL; pNode=pNode->pNext)
		{
		
			if (pNode->cb.tgKhoiHanh.ngay == Ngay && pNode->cb.tgKhoiHanh.thang == Thang && pNode->cb.tgKhoiHanh.nam == Nam)
			{
				for(int i = 0 ; i< pNode->cb.dsVe.n; i++)
				{
					if( pNode->cb.dsVe.ve[i] == cmnd ){
						return true;
					}
				}
				
			}
			
		}				
					
	
	return false;
}


void Dat_Ve(ListMayBay lmb, SingleList_CB &lcb, AVLTree &tree){
	ChuyenBay cb;
	
	DatVeTiep:
	int ngay;
	int tmp;// lay so dong de ve khung


	char cmnd[9];
	while(true)	
	{
		Box_Dat_Ve();
		
		SetColor(ColorWHITE);
		string temp;
		char macb[16], cmnd[9], chonGhe[15];
		int vitri = 0, soGhe = -1, socho = 0;
		NhapMaCB:
			do{
				gotoxy(15,25);
				temp = nhapChuoi(15,15,25);
				if(temp == "exit"){
				goto THOAT;
				}
				strcpy(macb,temp.c_str());
				strcpy(macb,fix_Ma(macb));
				if(Check_MaCB(lcb,macb)==true){
					if (lmb.soluong > 0)
						{
							for (int i = 0; i < lmb.soluong; i++)
							{
								if (TimKiem_CB(lcb, macb) != NULL)
								{
//							
										cb = TimKiem_CB(lcb, macb)->cb;
										if (strcmp(cb.soHieuMB, lmb.maybay[i]->soHieuMB ) == 0)
										{
											socho = lmb.maybay[i]->soCho;
											if (Check_ListVe_Full(TimKiem_CB(lcb, macb)->cb, socho) == false)
											{
									
												if (cb.trangThai == 3){
												gotoxy(15, 43); cout << "Chuyen bay da cat canh!!";
												Sleep(1500);
												gotoxy(15, 43); cout << "                        ";
												gotoxy(15, 25); cout<<"                    ";
												strcpy(macb,"");
												goto NhapMaCB;
												}
												else if (cb.trangThai == 0){
												gotoxy(15, 43); cout << "Chuyen bay da huy !!";
												Sleep(1500);
												gotoxy(15, 43); cout << "                    ";
												gotoxy(15, 25); cout<<"                    ";
												strcpy(macb,"");
												goto NhapMaCB;
												}
												else{
													XoaManHinhTrungTam();	// y =12 , x = 42+13 , chieu cao  = 34+3-1-1, chieu dai = 80+20-6
											//	VeHCN( 42+13,12,(80+20-6)/2 - 3, 32,255);
												int cot = 42+15, dong = 12+2;
												ngay = cb.tgKhoiHanh.ngay;
												for (int i = 0; i < socho; i++) {
													if (cb.dsVe.ve[i] == "") {
													SetColor(ColorWHITE);
													SetBGColor(ColorGREEN);
													gotoxy(cot, dong); cout << i+1;
													cot = cot + 5;
												}
												else if (cb.dsVe.ve[i] != "") {
													SetColor(ColorWHITE);
													SetBGColor(ColorRED);
													gotoxy(cot, dong); cout << i+1;
													cot = cot + 5;
												}
												if (cot % (42+15+ 40 )== 0) {
													dong = dong + 2;
													cot = 42+15;
													
												}
												tmp = dong;
												}
												
												SetColor(ColorWHITE);
												SetBGColor(ColorBLACK);
												VeHCN( 42+13,13,(80+20-6)/2 - 3-4, tmp-13+1,255);
												VeHCN( 42+13+((80+20-6)/2 -4),13,(80+20-6)/2 - 3-4, 25-13+1,255);
												goto ChonGhe;
												}
											}else if (Check_ListVe_Full(TimKiem_CB(lcb, macb)->cb, socho) == true) {
											gotoxy(15, 43); cout << "Ve da ban het !!!";
											Sleep(1000);
											gotoxy(15, 43); cout << "                 ";
											gotoxy(15, 25); cout<<"                   ";
											strcpy(macb, "");
											goto NhapMaCB;
											}
										}
								}		
							}
						}			
				}else{
						gotoxy(15, 43); 
					                	cout << "Chuyen bay khong co !!";
						Sleep(1500);
						gotoxy(15, 43); cout << "                       ";
						gotoxy(15, 25); cout<<"                       ";
						strcpy(macb,"");
						goto NhapMaCB;
					
					
				}
				
				
			
			}while(strcmp(macb, "") == 0);
		ChonGhe:
		do
		{
			strcpy(chonGhe,"");
			gotoxy(15,25+3);
			temp = nhapSo(3,15, 25+3);
			strcpy(chonGhe, temp.c_str());
			strcpy(chonGhe, fix_Ma(chonGhe));
			gotoxy(100,15);cout<<"                               ";
			gotoxy(100,17);cout<<"                               ";
			gotoxy(100,19);cout<<"                               ";
			gotoxy(100,21);cout<<"                               ";
			if (temp == "exit") {
				goto THOAT;
			}
			if (strcmp(chonGhe, "\0") == 0)
			{
				gotoxy(15, 43); cout << "Khong bo trong";
				Sleep(1000);
				gotoxy(15, 43); cout << "               ";
				goto ChonGhe;
			}
			else
			{
				int check = check_Chuoi_Char(chonGhe);
				if (check == 1)
				{
					soGhe = atoi(chonGhe);
					if (soGhe <= 0)
					{
						gotoxy(15, 43); cout << "Vi tri ghe khong hop le!";
						Sleep(2000);
						gotoxy(15, 43); cout << "                        ";
						gotoxy(15, 25+3); cout<<"             ";
						strcpy(chonGhe, "");
						goto ChonGhe;
					}
					else 
					{
						if (soGhe < socho) {
							if (cb.dsVe.ve[soGhe-1] != ""  ) {
								gotoxy(15, 43); cout << "Vi tri da co nguoi chon!";
								Sleep(500);
								char cmnd[16];
								strcpy(cmnd, cb.dsVe.ve[soGhe-1].c_str());
								AVLTree p = SearchHK(tree,cmnd);
								char hoten[150]; 
								char phai[5];
								char cmnddemo[16];
								strcpy(hoten,"");
								strcat(hoten, p->hanhkhach.ho );
								strcat(hoten, " ");
								strcat(hoten, p->hanhkhach.ten);
							
								strcpy(cmnddemo, p->hanhkhach.cmnd );
							
								strcpy(phai,p->hanhkhach.phai);
								SetColor(10);
								gotoxy(100,15);cout<<"Ho Ten    :"<<hoten;
								gotoxy(100,17);cout<<"CMND      :"<<cmnddemo;
								gotoxy(100,19);cout<<"Gioi Tinh :"<<phai;
								gotoxy(100,21);cout<<"So Ghe    :"<<soGhe;
								SetColor(255);
								
								gotoxy(15, 43); cout << "                         ";
								gotoxy(15, 25+3); cout<<"          ";
								strcpy(chonGhe, "");
								goto ChonGhe;
							}
							else if (cb.dsVe.ve[soGhe-1] == "") {
								goto NhapCMND;
							}
						}
						else if (soGhe > socho) {
							gotoxy(15, 43); cout << "Vi tri ghe khong ton tai";
							Sleep(1000);
							gotoxy(15, 43); cout << "                          ";
							gotoxy(15, 25+3); cout<<"                  ";
							strcpy(chonGhe, "");
							goto ChonGhe;
						}
					}
				}
				else
				{
					gotoxy(15, 43); cout << "KHONG HOP LE!";
					Sleep(1000);
					gotoxy(15, 43); cout << "              ";
					gotoxy(15, 25+3); cout<<"          ";
					strcpy(chonGhe, "");
					goto ChonGhe;
				}
				
				
			}
		} while (temp ==  "exit");


		
		NhapCMND:
		do{
			gotoxy(100,15);cout<<"                             ";
			gotoxy(100,17);cout<<"                             ";
			gotoxy(100,19);cout<<"                             ";
			gotoxy(100,21);cout<<"                             ";
			gotoxy(100,15);cout<<"                             ";
			SetColor(10);
			gotoxy(100,15);cout<<"So Ghe    :"<<soGhe;
			gotoxy(100,17);cout<<"Thong tin : Chua co nguoi dat ve";
			SetColor(255);
			gotoxy(15,31);
			string tempcmnd;
			temp = nhapSo(9,15,31); 
			if (temp == "exit")
			goto THOAT;
			tempcmnd = temp;
			strcpy(cmnd, temp.c_str());
			strcpy(cmnd, fix_Ma(cmnd));
			if (temp != "exit")
			{
				if (SearchHK(tree, cmnd) != NULL)
				{
					
					if (CheckHKTrongCB(cb.dsVe, socho, cmnd) == 1)
					{
						gotoxy(15, 43); cout << "Ban da mua ve chuyen nay!";
						Sleep(500);
						gotoxy(15, 43); cout << "                         ";
						gotoxy(15, 31); cout<<"                      ";
						goto NhapCMND;
					}else if(Check_Trung_Ve_Mot_Nguoi_Mot_Ngay(lcb,cb.tgKhoiHanh.ngay,cb.tgKhoiHanh.thang,cb.tgKhoiHanh.nam, tempcmnd)){
					
						gotoxy(15, 43); cout << "Ban da mua ve hom nay";
						Sleep(500);
						gotoxy(15, 43); cout << "                     ";
						gotoxy(15, 31); cout<<"                      ";
						goto NhapCMND;
					
					}
					else
					{
						
						AVLTree pHK = SearchHK(tree, cmnd);
						gotoxy(15, 34); 	cout << pHK->hanhkhach.ho;
						gotoxy(15, 37); 	cout << pHK->hanhkhach.ten;
						gotoxy(15, 40); cout <<	pHK->hanhkhach.phai;
						SetColor(10);
						gotoxy(100,19);cout<<"________________________________";
						gotoxy(100,21);cout<<"CMND      :"<<pHK->hanhkhach.cmnd;
						gotoxy(100,23);cout<<"Ho va ten :"<<pHK->hanhkhach.ho<<" "<<pHK->hanhkhach.ten;
						SetColor(255);
						int datve = XacNhanDatVe();
						if (datve == 1)
						{
							InsertVe(cb.dsVe, soGhe, cmnd);
							
							if (Check_ListVe_Full(TimKiem_CB(lcb, macb)->cb, socho) == true)
							{
								cb.trangThai = 2;



								Node_CB *pNode = SearchCB(lcb,macb);
								pNode->cb.trangThai = 2;
							

							}
							LuuFileChuyenBay(lcb, lmb);	
							XoaManHinhTrungTam();
							XoaManHinhThongBao1();
							SetColor(ColorWHITE);
							SetBGColor(ColorBLACK);
							gotoxy(12,23); 		cout << "                     ";
							gotoxy(15, 25); cout << "                        ";
							gotoxy(15, 28); cout << "                        ";
							gotoxy(15, 31); cout << "                        ";
							gotoxy(15, 34); cout << "                        ";
							gotoxy(15, 37); cout << "                        ";
							gotoxy(15, 40); cout << "                        ";
							goto DatVeTiep;
						}
						else
						{
							XoaManHinhTrungTam();
							XoaManHinhThongBao1();
							SetColor(ColorWHITE);
							SetBGColor(ColorBLACK);
							gotoxy(12,23); 		cout << "                     ";
							gotoxy(15, 25); cout << "                        ";
							gotoxy(15, 28); cout << "                        ";
							gotoxy(15, 31); cout << "                        ";
							gotoxy(15, 34); cout << "                        ";
							gotoxy(15, 37); cout << "                        ";
							gotoxy(15, 40); cout << "                        ";
							goto DatVeTiep;
						}
					}
				}
				else if (SearchHK(tree, cmnd) == NULL)
				{
					int a = XacNhanThemHanhKhach();
					if (a == 1){
						
						if(NhapHanhKhachDatVe(tree,cmnd)){
								AVLTree pHK = SearchHK(tree, cmnd);
								gotoxy(15, 34); SetBGColor(0);SetColor(1);cout << pHK->hanhkhach.ho;
								gotoxy(15, 37); SetBGColor(0);SetColor(1);cout << pHK->hanhkhach.ten;
								gotoxy(15, 40); SetBGColor(0);SetColor(1);cout <<	pHK->hanhkhach.phai;
								int datve = XacNhanDatVe();
							if (datve == 1)
							{
								InsertVe(cb.dsVe, soGhe,pHK->hanhkhach.cmnd);
							
								if (Check_ListVe_Full(TimKiem_CB(lcb, macb)->cb, socho) == true)
								{
									cb.trangThai = 2;


									Node_CB *pNode = SearchCB(lcb,macb);
									pNode->cb.trangThai = 2;
							

								}
								LuuFileChuyenBay(lcb, lmb);	
								XoaManHinhTrungTam();
								XoaManHinhThongBao1();
								SetColor(ColorWHITE);
								SetBGColor(ColorBLACK);
							gotoxy(12,23); 		cout << "                  ";
							gotoxy(15, 25); cout << "                      ";
							gotoxy(15, 28); cout << "                      ";
							gotoxy(15, 31); cout << "                      ";
							gotoxy(15, 34); cout << "                      ";
							gotoxy(15, 37); cout << "                      ";
							gotoxy(15, 40); cout << "                      ";
							gotoxy(15, 43); cout << "DAT VE THANH CONG";
							Sleep(500);
							gotoxy(15, 43); cout << "                       ";
							goto DatVeTiep;

						}else{
					
						XoaManHinhTrungTam();
						XoaManHinhThongBao1();
						SetColor(ColorWHITE);
						SetBGColor(ColorBLACK);
						gotoxy(12,23); 		cout << "                      ";
						gotoxy(15, 25); 	cout << "                      ";
						gotoxy(15, 28); 	cout << "                      ";
						gotoxy(15, 31); 	cout << "                      ";
						gotoxy(15, 34); 	cout << "                      ";
						gotoxy(15, 37); 	cout << "                      ";
						gotoxy(15, 40); 	cout << "                      ";
				
						goto NhapMaCB;
						}
							
							
							
							
						}else{
							
	
							XoaManHinhTrungTam();
						XoaManHinhThongBao1();
						SetColor(ColorWHITE);
						SetBGColor(ColorBLACK);
						gotoxy(12,23); 		cout << "                      ";
						gotoxy(15, 25); 	cout << "                      ";
						gotoxy(15, 28); 	cout << "                      ";
						gotoxy(15, 31); 	cout << "                      ";
						gotoxy(15, 34); 	cout << "                      ";
						gotoxy(15, 37); 	cout << "                      ";
						gotoxy(15, 40); 	cout << "                      ";
				
						goto NhapMaCB;
							
							
							
						}
						
					
					}
				}
			}
		}while(strcmp(cmnd, "") == 0);
		THOAT:
	//	XoaManHinhTuyChon(1,22,38,22);
	//	gotoxy(1,1); cout<<lcb.pHead->cb.trangThai;
		
	//	system("pause");
		
//		int a = XacNhanSaveFile();
//		if(a == 1){
//			LuuFileChuyenBay(lcb, lmb);
//			XoaManHinhThongBao2();
//		}
		XoaManHinhTrungTam();
		XoaManHinhThongBao2();
		break;
	
	
	
	}
 
}






void HuyVe(SingleList_CB &lcb, ListMayBay lmb){

	HuyVeTiep:
	
	
	char cmnd[17];

	int tmp;// lay so dong de ve khung
	while (true)
	{
		Box_Huy_Ve();
		
		SetColor(ColorWHITE);
		ChuyenBay cb;
		string temp;
		char macb[16], cmnd[17], chonGhe[15];
		int vitri = 0, soGhe = -1, socho = 0;
	
	NhapMaCB:
		do{
			gotoxy(15,25); cout<<"                  ";
			gotoxy(15,25);
			temp = nhapChuoi(15,15,25);
			if (temp == "exit")
				goto THOAT;
			strcpy(macb, temp.c_str());
			strcpy(macb, fix_Ma(macb));
			SetBGColor(ColorBLACK);
			if (Check_MaCB(lcb, macb) == true)
			{
				if (lmb.soluong > 0)
				{
					for (int i = 0; i < lmb.soluong; i++)
					{
						if (TimKiem_CB(lcb, macb) != NULL)
						{
							socho = lmb.maybay[i]->soCho;
							
							cb = TimKiem_CB(lcb, macb)->cb;
							if (cb.trangThai == 3){
								SetColor(ColorWHITE);
								gotoxy(15, 33); cout << "Chuyen bay da cat canh";
								gotoxy(15,34);cout<<"khong huy ve duoc!!";
								Sleep(1500);
								gotoxy(15, 33); cout << "                      ";
								gotoxy(15, 34); cout << "                      ";
								gotoxy(15, 25); cout<<"                    ";
								strcpy(macb,"");
								goto NhapMaCB;
							}
							else if (cb.trangThai == 0){
								SetColor(ColorWHITE);
								gotoxy(15, 33); cout << "Chuyen bay da huy!!";
								Sleep(1500);
								gotoxy(15, 33); cout << "                    ";
								gotoxy(41, 5); cout<<"                    ";
								strcpy(macb,"");
								goto NhapMaCB;
							}
							else{
								XoaManHinhTrungTam();
								int cot = 42+15, dong = 12+2;
								for (int i = 0; i < socho; i++) {
											if (cb.dsVe.ve[i] == "") {
											SetColor(ColorWHITE);
											SetBGColor(ColorGREEN);
											gotoxy(cot, dong); cout << i+1;
											cot = cot + 5;
									}
										else if (cb.dsVe.ve[i] != "") {
													SetColor(ColorWHITE);
													SetBGColor(ColorRED);
													gotoxy(cot, dong); cout << i+1;
													cot = cot + 5;
									}
											if (cot % (42+15+ 40 )== 0) {
													dong = dong + 2;
													cot = 42+15;
													
										}
												tmp = dong;
										}
												
										SetColor(ColorWHITE);
										SetBGColor(ColorBLACK);
										VeHCN( 42+13,13,(80+20-6)/2 - 3-4, tmp-13+1,255);
								goto ChonGhe;
							}	
						}	
					}
				}	
			}
			else{
				SetColor(ColorWHITE);
				gotoxy(15, 33); cout << "Ma CB khong ton tai!";
				Sleep(1000);
				gotoxy(15, 33); cout << "                     ";
				gotoxy(15, 33); cout<<"                     ";
				strcpy(macb, "");
				goto NhapMaCB;
			}
		}while(strcmp(macb, "") == 0);
		
	ChonGhe:
		do
		{
			strcpy(chonGhe,"");
			gotoxy(15,28);
			temp = nhapSo(3,15, 28);
			strcpy(chonGhe, temp.c_str());
			strcpy(chonGhe, fix_Ma(chonGhe));
			if (temp == "exit") {
				goto THOAT;
			}
			if (strcmp(chonGhe, "\0") == 0)
			{SetColor(ColorWHITE);
				gotoxy(15, 33); cout << "Khong bo trong";
				Sleep(1000);
				gotoxy(15, 33); cout << "               ";
				goto ChonGhe;
			}
			else
			{
				int check = check_Chuoi_Char(chonGhe);
				if (check == 1)
				{
					soGhe = atoi(chonGhe);
					if (soGhe <= 0)
					{SetColor(ColorWHITE);
						gotoxy(15, 33); cout << "Vi tri ghe khong hop le!";
						Sleep(2000);
						gotoxy(15, 33); cout << "                        ";
						gotoxy(15, 28); cout<<"                 ";
						strcpy(chonGhe, "");
						goto ChonGhe;
					}
					else 
					{
						if (soGhe <= socho) {
							if (cb.dsVe.ve[soGhe-1] != "") 
							{
								int huyve = XacNhanHuyVe();
								SetBGColor(ColorBLACK); SetColor(ColorWHITE);
								if (huyve == 1)
								{
									if (DeleteVe(cb.dsVe, soGhe) == true){
									//	gotoxy(boxx + 22, 29);

										SetColor(ColorWHITE);
									//	gotoxy(15,15);	cout << "HUY VE THANH CONG";
										Sleep(1000);
										XoaManHinhThongBao1();
										XoaManHinhTrungTam();
										
										
										goto HuyVeTiep;
									}else
									{
										gotoxy(15, 15);
										cout << "HUY VE THAT BAI";
										Sleep(1000);
										XoaManHinhThongBao1();
										XoaManHinhTrungTam();
									
										goto HuyVeTiep;
									}
									
								}
								else{
									XoaManHinhThongBao1();
									XoaManHinhTrungTam();
									
									goto HuyVeTiep;
								}
							}
							else if (cb.dsVe.ve[soGhe-1] == "") {
								gotoxy(15, 33); cout << "Vi tri ghe khong hop le!!";
								Sleep(2000);
								gotoxy(15, 33); cout << "                         ";
								gotoxy(15, 28); cout<<"                 ";
								strcpy(chonGhe, "");
								goto ChonGhe;
							}
						}
						else if (soGhe > socho) {
							gotoxy(15, 33); cout << "Vi tri ghe khong ton tai!";
							Sleep(2000);
							gotoxy(15, 33); cout << "                         ";
							gotoxy(15, 28); cout<<"              ";
							strcpy(chonGhe, "");
							goto ChonGhe;
						}
					}
				}
				else
				{
					gotoxy(15, 33); cout << "KHONG HOP LE!!";
					Sleep(2000);
					gotoxy(15, 33); cout << "               ";
					gotoxy(15, 28); cout<<"               ";
					strcpy(chonGhe, "");
					goto ChonGhe;
				}
				
			}	
			
		} while (temp ==  "exit");
	
	THOAT:
		int a = XacNhanSaveFile();
		if(a == 1){
			LuuFileChuyenBay(lcb, lmb);
			XoaManHinhThongBao2();
		}
	  XoaManHinhThongBao2();
		break;
	
	}
	
}

void Danh_Sach_ChuyenBay_DatVe(SingleList_CB &lcb, ListMayBay lmb,AVLTree &tree)
{	
	XoaManHinhHuongDan();
	
	int trang = 0, tongtrang = 0, i = 0;
	int soluong = CountCB(lcb);
	if (soluong <= 20)
	{
		trang = 0;
		tongtrang = 1;
	}
	else
	{
		tongtrang = (soluong / 21) + 1;
	}
	while(1)
	{
	Xuat:
		XoaManHinhThongBao1();
		XoaManHinhHuongDan();
		HuongDanDSVe();	
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		logo(3,10);
		TableChuyenBay();
		HienThiTrang(tongtrang, trang, 95, 39);
		Box_Menu_Ve();
		
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);
		
		gotoxy(tabxCB + 4, taby + 3);
		int dem = 0;
		int item = 0 + trang * 20;
		int itemtoida = 20 + trang * 20;
		
		for (Node_CB *pNode = lcb.pHead; pNode != NULL; pNode=pNode->pNext)
		{
			if (item < itemtoida && item < soluong)
			{
				int ngay = pNode->cb.tgKhoiHanh.ngay;
				int thang = pNode->cb.tgKhoiHanh.thang;
				int nam = pNode->cb.tgKhoiHanh.nam;
				int gio = pNode->cb.tgKhoiHanh.gio;
				int phut = pNode->cb.tgKhoiHanh.phut;
				
				if (Check_ThoiGian_ChuyenBay(pNode->cb.tgKhoiHanh) == false)
				 	pNode->cb.trangThai = 3;
				
				gotoxy(tabxCB + 4, taby + 3 + dem); cout <<dem+1;
				gotoxy(tabxCB + 12, taby + 3 + dem); cout<<pNode->cb.soHieuMB;
				gotoxy(tabxCB + 27, taby + 3 + dem); cout<<pNode->cb.maCB;
				gotoxy(tabxCB + 42, taby + 3 + dem); cout <<ngay<<"/"<<thang<<"/"<<nam;
				gotoxy(tabxCB + 60, taby + 3 + dem); cout<<gio<<":"<<phut;
				gotoxy(tabxCB + 73, taby + 3 + dem); cout <<pNode->cb.sanBayDen;
				gotoxy(tabxCB + 88, taby + 3 + dem); cout <<pNode->cb.trangThai;
				dem++;
				item++;
			}
		
		}
		
		gotoxy(96-7, 38);
		cout << "[<-] Tro lai | Tiep Theo [->]"; 
		
		int c = 0;
		do{
			c = getch();
		}while(c != LEFT && c != RIGHT && c!= ESC && c != F1 && c != F2 && c != F3 && c != F4);
		if (c == ESC)
		{
		//	ButtonESC(127);
	//		Sleep(500);
//			int a = XacNhanSaveFile();
//			if(a == 1)
//			{
//				LuuFileChuyenBay(lcb, lmb);
//			}
			ButtonESC(1);
			Sleep(500);

			XoaManHinhTrungTam();
			
			XoaManHinhHuongDan();
//		
			
			break;
		}
		else if (c == LEFT)
		{
			if(tongtrang > 1 && trang > 0)
			{
				trang--;
				goto Xuat;
			}
		}
		else if (c == RIGHT)
		{
			if(tongtrang > 1 && trang  + 1 < tongtrang)
			{
				trang++;
				goto Xuat;
			}
		}
		else if (c == F1)
		{
			Sleep(500);
			ButtonDatVe(1);
			Dat_Ve(lmb,lcb,tree);
			goto Xuat;
		}
		else if (c == F2)
		{
			Sleep(500);
			ButtonHuyVe(1);
			HuyVe(lcb, lmb);
		//	Sleep(500);
			XoaManHinhTrungTam();
		//	system("cls");
			goto Xuat;
		}
	
				
		
	}	
}





int MenuInDS(ListMayBay lmb, SingleList_CB lcb)
{	
	

	int keyhit;
	char menu_text2[4][100] = {"1. IN DANH SACH CAC HANH KHACH THUOC 1 CHUYEN BAY DUA VAO MA CHUYEN BAY    ", 
							  "2. IN DANH SACH CAC CHUYEN BAY KHOI HANH TRONG NGAY dd/mm/yyyy DEN NOI XXXX", 
							  "3. IN DANH SACH CAC VE CON TRONG CUA 1 CHUYEN BAY CO MA CHUYEN BAY LA X    ",
							  "4. THOAT                                                                   "};
	Menu:
		
	
	int x = 50, y = 14;
	
	gotoxy(1,13);SetBGColor(12);SetColor(255);cout<<" 4. IN DANH SACH                       ";
	gotoxy(41,13);SetBGColor(0);SetColor(255);cout<<"------>";
	VeHCN( 49,13,77, 5,255);
	//HuongDanMenuMain();

	for(int i = 0; i < 4; i++){
		gotoxy(x, y+i); cout << menu_text2[i];
	}
	
	SetBGColor(ColorBLUE);
	gotoxy(x, 14); cout << menu_text2[0];



	do{

		keyhit = getch();
		switch(keyhit){
			case UP:{
				gotoxy(50, y); 
				SetBGColor(0);
				cout << menu_text2[y-14];
				y--;
				if (y < 14) y = 17;
				break;
			}
			case DOWN:{
				gotoxy(50, y); 
				SetBGColor(0);
				cout << menu_text2[y-14];
				y++;
				if(y > 17) y = 14; 
				break;
			}
			case ESC:{
			
				
				XoaManHinhTrungTam();
				return 0;
			}
			case ENTER:{
				switch(y-14)
				{
					case 0:
					{
						SetBGColor(15);
						SetColor(1);
						
						Danh_Sach_HK_Trong_CB(lcb,lmb);
						XoaManHinhTrungTam();

			            XoaManHinhThongBao2();
						
						goto Menu;
					}	
					case 1:
					{
						SetBGColor(15);
						SetColor(1);
						Danh_Sach_ChuyenBay_Trong_Ngay(lcb, lmb);
						XoaManHinhTrungTam();

			            XoaManHinhThongBao2();
						
						goto Menu;
					}
					case 2:
					{
						SetBGColor(15);
						SetColor(1);
						Danh_Sach_Ve_Trong_CB(lcb,lmb);
						XoaManHinhTrungTam();
	
			            XoaManHinhThongBao2();
						goto Menu;
					}
					case 3:
					{
						SetBGColor(15);
						SetColor(1);
						XoaManHinhTrungTam();

						return 1;
					}



				}
			}
		}
		gotoxy(50, y); 
		SetBGColor(9);
		cout << menu_text2[y-14];
	
	}while(true);
		
		

}
	
void Menu(ListMayBay &lmb, SingleList_CB &lcb)
{	
	

	int keyhit;
	char menu_text[11][100] = {" 1. MAY BAY                            ", 
							   " 2. CHUYEN BAY                         ", 
							   " 3. DAT VE - HUY VE                    ",
							   " 4. IN DANH SACH                       ",
							   " 5. THONG KE                           ",
							   " 6. KET THUC                           "};
	Menu:
		
		SetColor(ColorWHITE); SetBGColor(ColorBLACK);

		gotoxy(70,3);cout <<"  ____  _   _  ___   __  _   _   ___    _   _   ___  _  _    __   __  _  _ ";
		gotoxy(70,4);cout <<" |  __| |   | |___|  | | |   |    |    | |_| | |___| |__|   |_ ) |__| |__| ";
		gotoxy(70,5);cout <<" |___ | |___| |   | _| |_|   |__ _|_   |     | |   |  __|   |__) |  |  __| ";
		gotoxy(70,6);cout <<"                                                                           ";
		
		
	
	int x = 1, y = 10;
	

	
	VeHCN( 0,0,166, 8,ColorWHITE);
	HuongDanMenuMain();

	for(int i = 0; i < 6; i++){
		gotoxy(x, y+i); cout << menu_text[i];
	}
	
	SetBGColor(ColorBLUE);
	gotoxy(x, 10); cout << menu_text[0];


    
	do{

		keyhit = getch();
		switch(keyhit){
			case UP:{
				gotoxy(1, y); 
				SetBGColor(0);
				cout << menu_text[y-10];
				y--;
				if (y < 10) y = 15;
				break;
			}
			case DOWN:{
				gotoxy(1, y); 
				SetBGColor(0);
				cout << menu_text[y-10];
				y++;
				if(y > 15) y = 10; 
				break;
			}
			case ENTER:{
				switch(y-10)
				{
					case 0:
					{
						SetBGColor(0);
						SetColor(1);
						
						Danh_Sach_MayBay(lmb, lcb);
						
						goto Menu;
					}	
					case 1:
					{
						SetBGColor(15);
						SetColor(1);
				
						Danh_Sach_ChuyenBay(lcb,lmb);
						goto Menu;
					}
					case 2:
					{
						SetBGColor(15);
						SetColor(1);
						//Dat_Ve(lmb, lcb, tree);
						Danh_Sach_ChuyenBay_DatVe(lcb,lmb,tree);
						goto Menu;
					}
					case 3:
					{
						SetBGColor(15);
						SetColor(1);
						
						MenuInDS(lmb, lcb);
						goto Menu;
					}
					case 4:
					{
						SetBGColor(15);
						SetColor(1);
						
						Danh_Sach_Thong_Ke_So_Luot_Bay(lcb,lmb);
						goto Menu;
					}
					case 5:
					{
						
							SetBGColor(14);
						SetColor(15);
						exit(0);
					}
				
	
				}
			}
		}
		gotoxy(1, y); 
		SetBGColor(9);
		cout << menu_text[y-10];
	
	}while(true);
}




int main(int argc, char** argv) {
	//resizeConsole(1360,700);
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
	VeHCN( 0,0,40, 32+14,ColorWHITE); // ve man hinh thong bao doc
	VeHCN( 0,0,166, 14+32,ColorWHITE);// ve BG
	VeHCN( 0,0,166, 8,ColorWHITE);// ve man hinh ngang
	VeHCN( 0,21,40, 32+14-21,ColorWHITE);
	ListMayBay lmb;
	SingleList_CB lcb;
	Init_CB(lcb);
	InitTreeHK(tree);
	DocFileHanhKhach(tree);
	DocFileMayBay(lmb);
	DocFileChuyenBay(lcb, lmb);


	Menu(lmb, lcb);

	return 0;
}
