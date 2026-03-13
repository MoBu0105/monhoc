#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int xd = 5, yd = 1, d = 10, stop;

//Cau truc
struct monhoc {
	char msmh[6];
	char ten[30];
	int stc, lt, th, tuh; //so tin chi, so gio ly thuyet, so gio thuc hanh, so gio tu hoc
};

//gotoxy
void xy(int x, int y)
{
	COORD td;

	td.X = x;
	td.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), td);
}

//menu chinh
string mn[] = {
	"CHUONG TRINH QUAN LY MON HOC",
	"1. In danh sach cac mon hoc",
	"2. Them mon hoc",
	"3. Xoa mon hoc",
	"4. Cap nhat mon hoc",
	"5. Tim kiem mon hoc",
	"6. Xap sep mon hoc",
	"7. Thong ke thong tin",
	"8. Loc mon hoc",
	"9. Thoat chuong trinh"

};

//menu them
string mn_them[] = {
	"CHON CACH THEM VAO DANH SACH",
	"1. Them dau",
	"2. Them cuoi",
	"3. Them vao stt duoc chon",
	"4. Them vao sau MSMH duoc chon",
	"5. Thoat"
};

//menu xoa
string mn_xoa[] = {
	"CHON CACH XOA DANH SACH",
	"1. Xoa dau",
	"2. Xoa cuoi",
	"3. Xoa theo stt",
	"4. Xoa sau msmh",
	"5. Thoat"
};

//menu tim kiem 1
string mn_tk1[] = {
	"CHON TIM KIEM THEO",
	"1. MSMH",
	"2. Ten mon hoc",
	"3. So tin chi",
	"4. So gio ly thuyet",
	"5. So gio thuc hanh",
	"6. So gio tu hoc",
	"7. Thoat"
};

//menu tim kiem 3
string mn_tk3[] = {
	"CHON PHUONG THUC TIM KIEM",
	"1. Tim lon nhat",
	"2. Tim nho nhat",
	"3. Tim tuy chon",
	"4. Thoat"
};

//menu sx 1
string mn_sx1[] = {
	"CHON PHUONG THUC SAP XEP",
	"1. Buble",
	"2. Skaker",
	"3. Selection",
	"4. Insertion",
	"5. InterChange",
	"6. Thoat"
};

//menu sx 2
string mn_sx2[] = {
	"CHON SAP XEP THEO",
	"1. MSMH",
	"2. Ten mon hoc",
	"3. So tin chi",
	"4. So gio ly thuyet",
	"5. So gio thuc hanh",
	"6. So gio tu hoc",
	"7. Thoat"
};

//menu sx 3
string mn_sx3[] = {
	"CHON LOAI XAP SEP",
	"1. Tang dan",
	"2. Giam dan",
	"3. Thoat"
};

//menu thong ke
string mn_thongke[] = {
	"CHON THONG TIN MUON THONG KE",
	"1. So tin chi",
	"2. So gio ly thuyet",
	"3. So gio thuc hanh",
	"4. So gio tu hoc",
	"5. Thoat"
};

//menu loc 1
string mn_loc1[] = {
	"CHON THONG TIN MUON LOC",
	"1. So tin chi",
	"2. So gio ly thuyet",
	"3. So gio thuc hanh",
	"4. So gio tu hoc",
	"5. Thoat"
};

//menu loc 2
string mn_loc2[] = {
	"CHON CACH THUC LOC",
	"1. Lon hon hoac bang",
	"2. Nho hon hoac bang",
	"3. Thoat"
};

//in menu
void inmn(string m[], int s, int x, int y)
{
	xy(x + 3.755 * d, y);
	cout << m[0];
	y++;
	for (int i = 1; i < s; i++)
	{
		xy(x + 3.755 * d, y);
		cout << m[i];
		y++;
	}
	y++;
	xy(x + 3.75 * d, y);
	cout << "Chon thao tac: ";
}

//tao node
struct node
{
	monhoc info;
	node* next;
};

//con tro
typedef node* pnode;

//tao danh sach
struct linklist
{
	pnode dau, cuoi;
};


void initial(linklist& l)
{
	l.dau = nullptr;
	l.cuoi = nullptr;
}

//ktr co rong khong
int empty(linklist l)
{
	return (l.dau == nullptr);
}

//tao node moi trong danh sach
pnode taonode(monhoc x)
{
	pnode p = new node;
	if (!p) return 0;
	else
	{
		p->info = x;
		p->next = nullptr;
		return p;
	}
}

//tk chung
pnode tkc(linklist l, monhoc m)
{
	pnode p = l.dau;
	while (p != NULL && strcmp(p->info.msmh, m.msmh) != 0)
		p = p->next;
	return p;
}

//them dau
void themdau(linklist& l, monhoc x)
{
	pnode p = taonode(x);
	if (empty(l))
	{
		l.dau = p;
		l.cuoi = p;
	}
	else
	{
		p->next = l.dau;
		l.dau = p;
	}
}

//them cuoi
void themcuoi(linklist& l, monhoc x)
{
	pnode p = taonode(x);
	if (empty(l))
	{
		l.dau = p;
		l.cuoi = p;
	}
	else
	{
		l.cuoi->next = p;
		l.cuoi = p;
	}
}

//them bat ki theo stt
void thembatki1(linklist& l, monhoc m)
{
	int x, i = 1;

	pnode p = taonode(m);

	cout << "\nchon stt muon them vao: ";
	cin >> x;

	if (empty(l))
	{
		l.dau = p;
		l.cuoi = p;
	}
	else if (p == nullptr)
		cout << "Stt ko hop le!";
	else
	{
		for (pnode q = l.dau; q != nullptr; q = q->next)
		{
			if (i == x - 1) {
				p->next = q->next;
				q->next = p;
			}
			i++;
		}
	}
}

//them bat ki sau msmh
void thembatki2(linklist& l, monhoc m)
{
	monhoc y;
	pnode p = taonode(m);

	cout << "\nchon msmh muon them vao phia sau: ";
	cin.ignore();
	cin.getline(y.msmh, 6);

	pnode k = l.dau;
	while (k != NULL && strcmp(k->info.msmh, y.msmh) != 0)
		k = k->next;

	if (empty(l))
	{
		l.dau = p;
		l.cuoi = p;
	}
	else if (k == l.cuoi)
		themcuoi(l, m);
	else if (k != NULL)
	{
		p->next = k->next;
		k->next = p;
	}
	else
	{
		cout << "\nKhong tim thay MSMH de them vao";
		stop = _getch();
	}
}

//them tong
void them(linklist& l)
{
	int chon;
	monhoc m;

	do {
		system("cls");
		inmn(mn_them, size(mn_them), xd, yd);
		cin >> chon;
		cin.ignore();
		system("cls");

		if (chon != 5)
		{
			cout << "MSMH: ";
			cin.getline(m.msmh, 6);
			cout << "Ten mon hoc: ";
			cin.getline(m.ten, 30);
			cout << "So tin chi: ";
			cin >> m.stc;
			cout << "So gio ly thuyet: ";
			cin >> m.lt;
			cout << "So gio thuc hanh: ";
			cin >> m.th;
			cout << "So gio tu hoc: ";
			cin >> m.tuh;
		}

		switch (chon)
		{
		case 1: themdau(l, m); break;
		case 2: themcuoi(l, m); break;
		case 3: thembatki1(l, m); break;
		case 4: thembatki2(l, m);
		}
		cout << "\nDa them thanh cong";
	} while (chon != 5);
}

//in tieu de
void intd(int x, int& y)
{
	xy(x + 4 * d, y);
	cout << endl;
	for (int i = 0; i < 111; i++)
		cout << "-";

	xy(x + 4 * d, y);
	cout << "THONG TIN MON HOC";

	cout << endl;
	for (int i = 0; i < 111; i++)
		cout << "-";
	y += 2;

	xy(x, y);
	cout << "STT";
	xy(x + 0.6 * d, y);
	cout << "MSMH";
	xy(x + 1.5 * d, y);
	cout << "Ten mon hoc";
	xy(x + 3.65 * d, y);
	cout << "So tin chi";
	xy(x + 4.95 * d, y);
	cout << "So gio ly thuyet";
	xy(x + 6.85 * d, y);
	cout << "So gio thuc hanh";
	xy(x + 8.75 * d, y);
	cout << "So gio tu hoc";

	cout << endl;
	for (int i = 0; i < 111; i++)
		cout << "-";
	y += 2;
}

//in 1 mon hoc
void inmh(monhoc m, int x, int& y)
{
	xy(x + 0.6 * d, y);
	cout << m.msmh;
	xy(x + 1.5 * d, y);
	cout << m.ten;
	xy(x + 4.15 * d, y);
	cout << m.stc;
	xy(x + 5.45 * d, y);
	cout << m.lt;
	xy(x + 7.35 * d, y);
	cout << m.th;
	xy(x + 9.25 * d, y);
	cout << m.tuh;
}

//in danh sach
void inds(linklist l)
{
	int i = 1;
	pnode p;
	intd(xd, yd);
	for (p = l.dau; p != nullptr; p = p->next)
	{
		xy(xd, yd);
		cout << i;
		inmh(p->info, xd, yd);
		yd++;
		i++;
	}
	yd = 1;
}

// doc file
int readfile(string f, linklist& l)
{
	monhoc x;
	ifstream file(f.c_str());

	if (!file.is_open())
		return 1;

	string line;
	getline(file, line);

	while (getline(file, line))
	{
		stringstream ss(line);

		ss.getline(x.msmh, 6, ',');
		ss.getline(x.ten, 30, ',');
		ss >> x.stc;
		ss >> x.lt;
		ss >> x.th;
		ss >> x.tuh;
		themcuoi(l, x);
	}
	return 0;
}

//tim kiem
void tk(linklist l)
{
	int chon1, chon2;
	char yn;
	monhoc m;

	cout << "nhap msmh can tim: ";
	cin >> m.msmh;

	if (tkc(l, m) != NULL)
	{
		cout << endl;
		inmh(tkc(l, m)->info, xd, yd);
	}
	else
		cout << "Khong tim thay msmh";
}

//xoa dau
void xoad(linklist& l)
{
	pnode p = l.dau;
	if (l.dau == l.cuoi)
	{
		l.dau = l.cuoi = nullptr;
		delete p;
	}
	else
	{
		l.dau = l.dau->next;
		delete p;
	}
}

//xoa cuoi
void xoac(linklist& l)
{
	pnode p = l.cuoi, x = l.dau;
	if (l.dau == l.cuoi)
	{
		l.dau = l.cuoi = nullptr;
		delete x;
	}
	else
	{
		while (x->next != l.cuoi)
			x = x->next;
		l.cuoi = x;
		l.cuoi->next = nullptr;
		delete p;
	}
}

//xoa msmh dc chon
void xoa1(linklist& l)
{
	monhoc y;
	pnode p, x = l.dau;

	cin.ignore();
	cout << "Chon stt muon xoa: ";
	cin.getline(y.msmh, 6);

	if (tkc(l, y) == NULL)
		cout << "Khong tim thay msmh can xoa";
	else
	{
		while (x->next != NULL && strcmp(x->next->info.msmh,y.msmh)!=0)
			x = x->next;
		p = x->next;
		x->next = x->next->next;
		delete p;
		cout << "Da xoa thanh cong";
	}
}

//xoa sau msmh dc chon
void xoa2(linklist& l)
{
	int i = 1;
	pnode p = l.dau, x;
	monhoc y;

	cin.ignore();
	cout << "chon msmh muon them phia sau: ";
	cin.getline(y.msmh, 6);

	if (tkc(l, y) == NULL)
		cout << "Khong tim thay msmh can xoa";
	else
	{
		p = tkc(l, y);
		x = p->next;
		if (x == NULL)
			cout << "ko co phan tu sau msmh da chon";
		else
		{
			p->next = p->next->next;
			delete x;
			cout << "Da xoa thanh cong";
		}
	}
}


//xoa tong
void xoa(linklist& l)
{
	int chon;
	system("cls");
	if (empty(l))
		cout << "Danh sach rong ko can xoa!";
	else
	{
		inmn(mn_xoa, size(mn_xoa), xd, yd);
		cin >> chon;
		system("cls");

		switch (chon)
		{
		case 1: 
			xoad(l);
			cout << "Da xoa thanh cong";
			break;
		case 2:
			xoac(l);
			cout << "Da xoa thanh cong";
			break;
		case 3:
			xoa1(l);
			break;
		case 4:
			xoa2(l);
		}
	}
}



int main()
{
	linklist l;
	initial(l);
	string filein = "thong_tin_mon_hoc.txt";
	int chon1;

	xy(xd + 1.5 * d, yd + 10.5);
	cout << "Vui long chinh co chu len 36 de co trai nghiem tot nhat! Xin cam on";
	xy(xd + 2.9 * d, yd + 11.5);
	cout << "Nhan phim bat ki de bat dau chuong trinh";
	stop = _getch();
	system("cls");

	if (readfile(filein, l) == 1)
	{
		xy(xd + 3.5 * d, yd + 10.5);
		cout << "Khong doc duoc file!";
		stop = _getch();
	}

	do {
		system("cls");
		inmn(mn, size(mn), xd, yd);
		cin >> chon1;
		cin.ignore();
		switch (chon1)
		{
		case 1:
			system("cls");
			inds(l);
			stop = _getch();
			break;
		case 2:
			system("cls");
			them(l);
			break;
		case 3:
			system("cls");
			xoa(l);
			stop = _getch();
			break;
			/*case 4:
				system("cls");
				cn(ds, sl);
				stop = _getch();
				break;*/
		case 5:
			system("cls");
			tk(l);
			stop = _getch();
			break;
			/*case 6:
				system("cls");
				sapxep(ds, sl, sx);
				break;
			case 7:
				system("cls");
				thongke(ds, sl);
				stop = _getch();
				break;
			case 8:
				system("cls");
				loc(ds, sl);
				stop = _getch();*/
		}
	} while (chon1 != 9);

	system("cls");
	xy(xd + 3.4 * d, yd + 10.5);
	cout << "Cam on da su dung chuong trinh! (^w^)";

	stop = _getch();
	return 0;
}
