#include <iostream>
#include "Stock.h"
#include "Windows.h"
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	cout << "������ ������ ������������ ��� �������� ����� �������� \n";
	Stock stock1("NanoSmart ", 12, 20.0);
	stock1.show();
	Stock stock2 = Stock(" Boffo Objects ", 2, 2.0);
	stock2.show();
	cout << " ���������� stock1 stock2 : \n";
	stock2 = stock1;
	cout << "������� stock1 � stock2 : \n";
	stock1.show();
	stock2.show();
	cout << " ������123���� ������������ ��� ������ ������� \n";
	stock1 = Stock("Nifty Foods ", 10, 50.0);
	cout << "���������� stock1 : \n";
	stock1.show();
	cout << " ������\n";
	return 0;
}