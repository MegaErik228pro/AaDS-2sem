#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n, x, a, m, kol = 0;
	cout << "������� ����� N ";
	cin >> n;
	x = n / 2;
	int x1 = n;
	cout << x << endl;

	cout << "1 - ���� \n2 - �����\n3 - ������" << endl;
	cin >> a;
	do {
	switch(a)
	{
	case 1: m = abs(x1 - x); x1 = x; x = abs(m / 2 + x1); if (x == x1) { x++; } cout << x << endl << "1 - ���� \n2 - �����\n3 - ������" << endl; kol++;  cin >> a; break;
	case 2: m = abs(x1 - x); x1 = x; x = abs(m / 2 - x1); if (x == x1) { x--; } cout << x << endl << "1 - ���� \n2 - �����\n3 - ������" << endl; kol++; cin >> a; break;
	}
	} while (a != 3);
	cout << "���" << endl; cout << "���������� ����� " << kol + 1;
}