#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "Stock.h" 
using namespace std;

Stock::Stock()
{
	cout << "������ ����������� �� ���������\n";
	strcpy(company, " ��� �����");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char* ��, int n, double pr)
{
	cout << "������ ����������� ��� " << �� << "\n";
	strncpy(company, ��, 29);
	company[29] = ' \ 0';
	if (n < 0)
	{
		cerr << "���������� ������� �� ����� ���� ������������� ��� " << company << " ����������� � �. \n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock()
{
	cout << "�� �������, " << company << "!\n";
}


void Stock::buy(int num, double price)
{
	if (num < 0)
	{
		cerr << "���������� ������������� ������� �� ����� ���� �������������." << " ���������� �������� .\n";
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
	cerr;
	if (num < 0)
	{
		cerr << "���������� ��������� ������� �� ����� ���� �������������. " << " ���������� ��������.\n";
	}
	else if (num > shares)
	{
		cerr << "�� �� ������ ������� ������ ���� , ��� ��������! " << " ���������� �������� .\n";
	}
	else
		shares -= num;
	share_val = price;
	set_tot();
}
void Stock::update(double price)
{
	share_val = price;
	set_tot();
}
void Stock::show()
{
	cout << " �������� : " << company << endl;
	cout << " ������� : " << shares << endl;
	cout << " ���� ������ : $" << share_val << endl;
	cout << " ����� ��������� : $" << total_val << endl;
}