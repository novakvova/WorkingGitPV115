#include <iostream>
#include <Windows.h>
#include "stocks.h"
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout << "Используются конструкторы для создания новых объектов \n";
	Stock stock1("NanoSmart ", 12, 20.0);
	stock1.show();
	Stock stock2 = Stock(" Boffo Obj ects ", 2, 2.0);
	stock2.show();
	cout << " Присвоение stock1 stock2 : \n ";
	stock2 = stock1;
	cout << "Листинг stock1 и stock2 : \n ";
	stock1.show();
	stock2.show();
	cout << " Применение конструктора для сброса объекта \n";
	stock1 = Stock("Nifty Foods ", 10, 50.0);
	cout << "Измененный stock1 : \n";
	stock1.show();
	cout << " Готово\ n";
	return 0;
}