#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAXDSK = 15; //so dinh toi da
const int MAXDSC = MAXDSK * MAXDSK; // so canh toi da
struct NODE {
	int dinhke;
	int trongso = 0;
	NODE* link;
};
struct DANHSACHKE {
	NODE* dsk[MAXDSK];
	int n = 0;//so dinh cua do thi
};
struct CANH {
	int dau;
	int cuoi;
	int trongso = 0;
};
struct DANHSACHCANH {
	CANH ds[MAXDSC];
	int n = 0;//so canh cua do thi
};

//Ham tao danh sach ke tu file
// flag = 0:do thi khong trong so;  1:do thi co trong so
int docFile(const char*, DANHSACHKE&, int flag = 0);

//Ham ghi danh sach ke ra file
int ghiFile(const char*, DANHSACHKE&, int flag = 0);

//Ham xuat danh sach ke
void xuatDSK(DANHSACHKE);

//Ham huy danh sach ke
void huyDSK(DANHSACHKE&);

//Ham dem so dinh ke cua mot node
int demNode(NODE*);

//Ham lay tap canh cua do thi
DANHSACHCANH layDSC(DANHSACHKE);

//Ham xuat canh theo dinh dang: (dau, cuoi, trong so)
void xuatCanh(CANH);

//Ham tinh so bac vao cua mot dinh
int tinhSoBacVao(DANHSACHKE, int);
//Ham tinh so bac ra cua mot dinh
int tinhSoBacRa(DANHSACHKE , int );
//Ham tinh so bac  cua mot dinh VoHUONG
int tinhBacVH(DANHSACHKE dsk, int dinh);
