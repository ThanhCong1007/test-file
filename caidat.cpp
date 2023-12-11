#include "thuvien.h"
int docFile(const char* tenfile, DANHSACHKE& x, int flag) {

	FILE* f = fopen(tenfile, "rt");
	if (f == NULL) return 0;
	fscanf(f, "%d", &x.n);
	for (int i = 0; i < x.n; i++)
		x.dsk[i] = NULL;
	for (int i = 0; i < x.n; i++)
	{
		int m;
		fscanf(f, "%d", &m);
		for (int j = 0; j < m; j++)
		{
			NODE* p = new NODE;
			fscanf(f, "%d%d", &p->dinhke, &p->trongso);
			p->link = x.dsk[i];
			x.dsk[i] = p;
		}
	}
	fclose(f);
	return 1;
}
int demNode(NODE* p) {
	int dem = 0;
	while (p != NULL) {
		dem++;
		p = p->link;
	}
	return dem;
}
int ghiFile(const char* tenfile, DANHSACHKE& x, int flag) {
	FILE* f = fopen(tenfile, "wt");
	if (f == NULL) return 0;
	fprintf(f, "%d", x.n);
	for (int i = 0; i < x.n; i++) {
		NODE* p = x.dsk[i];
		int m = demNode(p);
		fprintf(f, "\n%d", m);
		while (p != NULL) {
			if (flag)
				fprintf(f, " %d %d", p->dinhke, p->trongso);
			else
				fprintf(f, " %d", p->dinhke);
			p = p->link;
		}
	}
	fclose(f);
	return 1;
}
void huyDSK(DANHSACHKE& x) {
	for (int i = 0; i < x.n; i++) {
		NODE* p = x.dsk[i];
		while (p != NULL) {
			NODE* q = p;
			p = p->link;
			delete q;
		}
		x.dsk[i] = NULL;
	}
}
void xuatDSK(DANHSACHKE x) {
	cout << endl;
	for (int i = 0; i < x.n; i++) {
		cout << endl;
		NODE* p = x.dsk[i];
		cout << i << ": ";
		while (p != NULL) {
			cout << " (" << p->dinhke << "," << p->trongso << ")";
			p = p->link;
		}
	}
}
DANHSACHCANH layDSC(DANHSACHKE x) {
	DANHSACHCANH dsc;
	for (int i = 0; i < x.n; i++) {
		NODE* p = x.dsk[i];
		while (p != NULL) {
			CANH c = { i, p->dinhke, p->trongso };
			dsc.ds[dsc.n] = c;
			dsc.n++;
			p = p->link;
		}
	}
	return dsc;
}
void xuatCanh(CANH c) {
	cout << "(" << c.dau << ", " << c.cuoi << ", " << c.trongso << ")";
}
int tinhSoBacVao(DANHSACHKE dsk, int dinh) {
	int dem = 0;
	for (int i = 0; i < dsk.n; i++) {
		if (i == dinh) continue;
		NODE* p = dsk.dsk[i];
		while (p != NULL) {
			if (p->dinhke == dinh)
				dem++;
			p = p->link;
		}
	}
	return dem;
}
int tinhSoBacRa(DANHSACHKE dsk, int dinh) {
	int dem = 0;
		NODE * p = dsk.dsk[dinh];
		while (p != NULL)
		{
			dem++;
			p = p->link;
		}
	return dem;
}
int tinhBacVH(DANHSACHKE dsk, int dinh) {
	int dem = 0;
	NODE * p = dsk.dsk[dinh];
	while (p != NULL)
	{
		dem++;
		p = p->link;
	}
	return dem;
}
