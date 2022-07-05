#pragma once
#include <iostream>
#include "Admin.h"

using namespace std;

class Oficiant : public Admin
{
private:
	int zakazov;
	string likeAnimal;

public:
	Oficiant();
	Oficiant(int m_zakazov, string likeAnim, string m_name);
	
	void setZakazov(int m_zakazov);
	void setlikeAnimal(string m_favoriteAnimal);
	
	int getZakazov();
	string GetfavoriteAnimal();

	void showInfo();
	fstream& writeToFile(fstream& m_of);
};

