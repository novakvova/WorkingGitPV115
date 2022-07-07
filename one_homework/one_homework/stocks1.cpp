#include <iostream>
#include "stocks.h"
using namespace std;
Stock::Stock()
{
	cout << " Вызван конструктор по умолчанию\n ";
	strcpy_s(company, "без имени");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char* сo, int n, double pr)
{
	cout << " Вызван конструктор для " << сo << " \n ";
	strncpy_s(company, сo, 29);
	company[29] = ' \ 0';
	if (n < 0)
	{
		cerr << " Количество пакетов не может быт ь отрицательным; для " << company << " установлено в О. \n";
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
	cout << "До встречи, " << company << "!\n ";
}
void Stock::buy(int num, double price)
{
	if (num < 0)
	{

		cerr << "Количество приобретаемых пакетов не может быть отрицательным." << " Транзакция прервана . \n ";
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
		cerr << " Количество проданных пакетов не может быть отрицательным . " << " Транзакция прервана . \n ";

	}
	else if (num > shares)
	{
		cerr << " Вы не можете продать больше того , чем владеете ! " << " Транзакция прервана . \n ";

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
	cout << " Компания:" << company << "Пакетов:" << shares << endl << " Цена пакета : $" << share_val << " Обшая стоимость : $" << total_val << endl;
}

