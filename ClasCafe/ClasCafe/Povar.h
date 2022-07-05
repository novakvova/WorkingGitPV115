#pragma once
#include <iostream>
#include "Admin.h"


using namespace std;

class Povar : public Admin
{
private:
	int zarplata;
	string favoriteEat;

public:
	Povar();
	
	void setZarplata(int m_zarplata);
	void setFavoriteEat(string m_favoriteEat);
	
	int getZarplata();
	string GetfavoriteEat();

	Povar(int m_zarplata, string m_favoriteFood, string m_name);

	void showInfo();
	fstream& writeToFile(fstream& m_of);
};

