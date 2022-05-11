#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<fstream>
#include<cstring>

using namespace std;


struct HanhKhach{
	HanhKhach(){};
	HanhKhach(const char* Cmnd, const char* Ho, const char* Ten,const char* Phai){
		strcpy(cmnd,Cmnd);
		strcpy(ho,Ho);
		strcpy(ten,Ten);
		strcpy(phai,Phai);
	}
	
	void operator=(const HanhKhach& hanhkhach){
	
		strcpy(cmnd,hanhkhach.cmnd);
		strcpy(ho,hanhkhach.ho);
		strcpy(ten,hanhkhach.ten);
		strcpy(phai,hanhkhach.phai);
	}
	int operator>(const HanhKhach& hanhkhach){
		return strcmp(cmnd,hanhkhach.cmnd)>0;
	}
	int operator<(const HanhKhach& hanhkhach){
		return strcmp(cmnd,hanhkhach.cmnd)<0;
	}
	char cmnd[16];
	char ho[100];
	char ten[100];
	char phai[10]; 
};

struct tagAVLNode{
	HanhKhach hanhkhach;
	int height;
	tagAVLNode *pLeft,*pRight;
};
typedef tagAVLNode AVLNode;
typedef AVLNode *AVLTree;
AVLTree tree;

void InitTreeHK(AVLTree &Root)
{
        Root = NULL;
}

bool CompareByName(AVLTree  &a,AVLTree  &b){//Sap xep theo tang dan cua ten
	return strcmp(a->hanhkhach.ten,b->hanhkhach.ten)<=0;
}

AVLTree CreateNode(const HanhKhach& hk){
	AVLTree node=new AVLNode;
	node->hanhkhach=hk;  
	node->height=1;
	node->pLeft=NULL;
	node->pRight=NULL;
	return node;
}

int GetNodeHeight(AVLTree &node){
	if(node==NULL) return 0;
	return node->height;
}

int GetNodeBalanceFactor(AVLTree &node){
	if(node==NULL) return 0;
	return GetNodeHeight(node->pLeft)-GetNodeHeight(node->pRight);
}

AVLTree RightRotate(AVLTree &root){// lenh ve ben trai thi quay ben phai
	//Xoay
	AVLTree nextroot=root->pLeft;
	root->pLeft=nextroot->pRight;
	nextroot->pRight=root;
	
	//Cap nhat do cao
	root->height=max(GetNodeHeight(root->pLeft),GetNodeHeight(root->pRight))+1;
	nextroot->height=max(GetNodeHeight(nextroot->pLeft),GetNodeHeight(nextroot->pRight))+1;
	return nextroot;
}

AVLTree LeftRotate(AVLTree  &root){
	AVLTree nextroot=root->pRight;
	root->pRight=nextroot->pLeft;
	nextroot->pLeft=root;
	
	root->height=max(GetNodeHeight(root->pLeft),GetNodeHeight(root->pRight))+1;
	nextroot->height=max(GetNodeHeight(nextroot->pLeft),GetNodeHeight(nextroot->pRight))+1;
	return nextroot;
}

AVLTree InsertNode(AVLTree  &root, HanhKhach& hk){
	if(root==NULL) {
		AVLTree  node=CreateNode(hk);
		
		
		return node;
	}
	if(hk > root->hanhkhach) root->pRight=InsertNode(root->pRight,hk);
	else root->pLeft=InsertNode(root->pLeft,hk);
	//Khong co truong hop bang
	
	root->height=max(GetNodeHeight(root->pLeft),GetNodeHeight(root->pRight))+1;
	int bf=GetNodeBalanceFactor(root);
	
	if(bf>1&&hk<root->pLeft->hanhkhach) { //pLeft pLeft
		return RightRotate(root);
	}
	if(bf>1&&hk>root->pLeft->hanhkhach){ //pLeft pRight
		root->pLeft=LeftRotate(root->pLeft);
		return RightRotate(root);
	}
	
	if(bf<-1&&hk>root->pRight->hanhkhach){//pRight pRight
		return LeftRotate(root);
	}
	if(bf<-1&&hk<root->pRight->hanhkhach){// pRight pLeft
		root->pRight=RightRotate(root->pRight);
		return LeftRotate(root);
	}
		
	return root;
}
AVLTree GetMinNode(AVLTree root){
		while(root->pLeft!=NULL) root=root->pLeft;
		return root;
	}
AVLTree DeleteNode(AVLTree  &root, HanhKhach& hk){//Ham nay se khong xoa vung nho vung nho du lieu se duoc tra lai
		if(root==NULL) return root;
		
		AVLTree renode;
		AVLTree nextnode;
		
		if(hk < root->hanhkhach) {
			nextnode=root->pLeft;
			renode=DeleteNode(nextnode,hk);
			root->pLeft=nextnode;
		}
		else if(hk > root->hanhkhach) {
			nextnode=root->pRight;
			renode=DeleteNode(nextnode,hk);
			root->pRight=nextnode;
		}
		else{//Truong hop bang
			if(root->pRight==NULL||root->pLeft==NULL){//nut nay chua mot nut la hoac khong chu nut la nao, truong hop khong can xoay cay
				AVLTree tmp=root->pRight?root->pRight:root->pLeft;
				
				if(tmp==NULL){//Truong hop nay khong can cap nhat lai cay
					AVLTree tmp=root;
					root=NULL;
					return tmp;
				}
				else{//Do cao giam co the anh huong toi do cao cua nut cha
					root=tmp;//xoa root, dua node len cho root
	//				root->left=NULL;
	//				root->right=NULL;
	//				s
					//Xoa vung nho cua tmp
					renode=tmp;
				}
				
			}
			else { //Lay nut cuc trai
				AVLTree tmp=GetMinNode(root->pRight);
	//			Node* tmp=GetMinValueNode(root->right);//Nut cuc trai cua cay con ben phai
	//			root->material=tmp->material;//Lay noi dung cu nut cuc trai
				//Sap chep key  va data cua nut cuc trai  
				root->hanhkhach=tmp->hanhkhach;
				
				
				nextnode=root->pRight;
				renode=DeleteNode(nextnode,tmp->hanhkhach);//Xoa nut cuc trai;
				root->pRight=nextnode;
			}
		}
		
		root->height=max(GetNodeHeight(root->pLeft),GetNodeHeight(root->pRight))+1;
		int bf=GetNodeBalanceFactor(root);	
			
		if(bf>1&&GetNodeBalanceFactor(root->pLeft)>=0){//LEFT LEFT
			root=RightRotate(root);
		}
		else if(bf>1&&GetNodeBalanceFactor(root->pLeft)<0){//LEFT RIGHT
			root->pLeft=LeftRotate(root->pLeft);
			root=RightRotate(root);
		}
		else if(bf<-1&&GetNodeBalanceFactor(root->pRight)<=0){//RIGHT RIGHT
			root=LeftRotate(root);
		}
		else if(bf<-1&&GetNodeBalanceFactor(root->pRight)>0){//RIGHT LEFT
			root->pRight=RightRotate(root->pRight);
			root= LeftRotate(root);
		}
		
		
		return renode;
}

//void quickSortHanhKhach(AVLTree Data[], int l , int r)
//{	
//	if (l <= r)
//	{
//		
//		char key[45];
// 		strcpy(key,Data[(l+r)/2]->hanhkhach.name);
//		int i = l;
//		int j = r;
// 
//		while (i <= j)
//		{
//			while (stricmp(Data[i]->hanhkhach.name,key)<0)
//				i++;
//			while (stricmp(Data[j]->hanhkhach.name,key)>0)
//				j--;
// 
//			if (i <= j)
//			{
//				swap(Data[i],Data[j]);
//				i++;
//				j--;
//			}
//		}
// 
//	
//		if (l < j)
//			quickSortMaterial(Data, l, j);
//		if (r > i)
//			quickSortMaterial(Data, i, r);
//	}
//}








AVLTree GetMinValueNode(AVLTree &root){
	while(root->pLeft!=NULL)
	 	root=root->pLeft;
	return root;
}

AVLTree SearchHK(AVLTree root,char cmnd[]){
	while(root!=NULL){
		if(stricmp(cmnd,root->hanhkhach.cmnd)<0) root=root->pLeft;
		else if(stricmp(cmnd,root->hanhkhach.cmnd)>0) root=root->pRight;
		else break;
	}
	return root;
}

bool CheckCMNDIsExisted(AVLTree tree_hk, char cmnd[])
{
	if (tree_hk != NULL)
	{
		if (strcmp(tree_hk->hanhkhach.cmnd,cmnd) == 0)
			return true;
		if (strcmp(tree_hk->hanhkhach.cmnd, cmnd) > 0)
			CheckCMNDIsExisted(tree_hk->pLeft, cmnd);
		else 
			CheckCMNDIsExisted(tree_hk->pRight, cmnd);
	}
	return false;
}




void PrintTree(AVLTree tree_hk)
{
	if (tree_hk != NULL)
	{
		string gt = "";
		HanhKhach hk = tree_hk->hanhkhach;
		
		gt = hk.phai==0?"Nu":"Nam";
		cout<<hk.cmnd<<"\t"<<hk.ho<<"\t"<<hk.ten<<"\t"<<gt<<endl;
		PrintTree(tree_hk->pLeft);
		PrintTree(tree_hk->pRight);
	}
}


void InsertHKToTree(AVLTree &tree_hk, HanhKhach hk)
{
	if (tree_hk == NULL)
	{
		AVLTree node=CreateNode(hk);
		tree_hk = node;
	}
	else
	{
		tree_hk = InsertNode(tree_hk,hk);
		
	}
}

