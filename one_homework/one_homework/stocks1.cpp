#include <iostream>
#include "stocks.h"
using namespace std;
Stock::Stock()
{
	cout << " ������ ����������� �� ���������\n ";
	strcpy_s(company, "��� �����");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char* �o, int n, double pr)
{
	cout << " ������ ����������� ��� " << �o << " \n ";
	strncpy_s(company, �o, 29);
	company[29] = ' \ 0';
	if (n < 0)
	{
		cerr << " ���������� ������� �� ����� ��� � �������������; ��� " << company << " ����������� � �. \n";
		shares = 0;
	}
	else
	{
		shares = n;
		share_val = pr;
		set_tot();
	}
}
Stock:: ~Stock()
{
	cout << "�� �������, " << company << "!\n ";
}
void Stock::buy(int num, double price)
{
	if (num < 0)
	{

		cerr << "���������� ������������� ������� �� ����� ���� �������������." << " ���������� �������� . \n ";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}

}
void Stock::sell(int num, double price)
{

	if (num < 0)
	{
		cerr << " ���������� ��������� ������� �� ����� ���� ������������� . " << " ���������� �������� . \n ";

	}
	else if (num > shares)
	{
		cerr << " �� �� ������ ������� ������ ���� , ��� �������� ! " << " ���������� �������� . \n ";

	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price)
{
	share_val = price;
	set_tot();
}
void Stock::show()
{
	cout << " ��������:" << company << "�������:" << shares << endl << " ���� ������ : $" << share_val << " ����� ��������� : $" << total_val << endl;
}

