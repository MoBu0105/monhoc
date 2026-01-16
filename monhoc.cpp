#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int xd = 10, yd = 1, d = 10, stop;

//Cau truc
struct monhoc {
	char msmh[6];
	char ten[10];
	int stc, lt, th, tuh;
};

//gotoxy
void xy(int x, int y)
{
	COORD td;

	td.X = x;
	td.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_INPUT_HANDLE), td);
}

//doc file
int readfile(string f, monhoc n[], int& sl)
{
	int i = 0;
	ifstream file(f.c_str());

	if (!file.is_open()) 
		return 1;

	string line;
	getline(file, line);

	while (getline(file, line))
	{
		stringstream ss(line);

		ss.getline(n[i].msmh, 6, ',');
		ss.getline(n[i].ten, 10, ',');
		ss >> n[i].stc;
		ss >> n[i].lt;
		ss >> n[i].th;
		ss >> n[i].tuh;

		i++;
	}

	sl = i;

	return 0;
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
	"7. Thoat chuong trinh"
};

//in menu
void inmn(string m[], int s, int x, int y)
{
	xy(x + 3.75 * d, y);
	cout << m[0];
	y++;
	for (int i = 1; i < s; i++)
	{
		xy(x + 3.75 * d, y);
		cout << m[i];
		y++;
	}

	y++;
	xy(x + 3.75 * d, y);
	cout << "Chon thao tac: ";
}

int main()
{
	monhoc ds[10];
	string filein = "thongtin.txt";
	int sl, chon1, chon2;

	if (readfile(filein, ds, sl) == 1)
	{
		cout << "Khong doc duoc file!";
		stop = _getch();
	}

	do{
		inmn(mn, size(mn), xd, yd);
		cin >> chon1;

	} while (chon1 != 7);
}
