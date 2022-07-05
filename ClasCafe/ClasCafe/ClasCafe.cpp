
#include <iostream>
#include <string>
#include<fstream>

#include "admin.h"
#include "oficiant.h"
#include "Povar.h"

using namespace std;

const int number = 2;




int main()
{
	fstream of;
	of.open("myfile.txt");

	if (of.is_open())
	{
		cout << "FILE READY TO USE!!" << endl;
	}

	Admin* list[number]{};
	Admin* list2[number]{};

	for (int i = 0; i < number; i++)
	{
		int action;

		string favAnim;
		string m_name;
		int zakaz;

		int m_zarplata;
		string favFood;

		cout << "Enter which you want create(1 - Oficiant; 2-Povar): ";
		cin >> action;

		if (action == 1)
		{
			cout << "Enter zakazov: ";
			cin >> zakaz;
			cout << endl;

			cout << "Enter favorite animal: ";
			cin >> favAnim;
			cout << endl;

			cout << "Enter name: ";
			cin >> m_name;
			cout << endl;
			list[i] = new Oficiant(zakaz, favAnim, m_name);
		}

		if (action == 2)
		{
			cout << "Enter zarplata: ";
			cin >> m_zarplata;
			cout << endl;

			cout << "Enter favorite food: ";
			cin >> favFood;
			cout << endl;

			cout << "Enter name: ";
			cin >> m_name;
			cout << endl;

			list[i] = new Povar(m_zarplata, favFood, m_name);
		}
	}

	for (int i = 0; i < number; i++)
	{
		list[i]->showInfo();
		list[i]->writeToFile(of);
		cout << endl;
		cout << endl;
	}

	of.close();
	of.open("myfile.txt");

	int d = 0;

	char f_name[100];
	char f_likeAnimal[100];
	char f_likeFood[100];

	int f_type;
	int f_zakazov;
	int f_zarplata;

	while (!of.eof())
	{
		of >> f_type;
		
		/*переміщаємо вказівник на новий рядок*/
		of.getline(f_name, 100, '\n');
		of.getline(f_name, 100, '\n');
		

		if (f_type == 0)
		{
			of >> f_zarplata;
			of.getline(f_likeFood, 100);
			of.getline(f_likeFood, 100);

			if (d >= number)
			{
				continue;
			}

			list2[d] = new Povar(f_zarplata, f_likeFood, f_name);
			d++;
		}

		if (f_type == 1)
		{
			of >> f_zakazov;
			of.getline(f_likeAnimal, 100, '\n');
			of.getline(f_likeAnimal, 100, '\n');

			if (d >= number)
			{
				continue;
			}

			list2[d] = new Oficiant(f_zakazov, f_likeAnimal, f_name);
			d++;
		}
	}

	cout << "Your masiv: " << endl;

	for (int i = 0; i < number; i++)
	{
		cout << endl << i + 1 << "#" << endl;
		list2[i]->showInfo();
		cout << endl;
	}
	

	of.close();
}

