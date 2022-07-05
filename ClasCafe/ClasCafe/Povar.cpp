#include "Povar.h"
#include <fstream>

Povar::Povar() 
{
	zarplata = 0;
	favoriteEat = "none";
}



void Povar::setZarplata(int m_zarplata)
{
	if (m_zarplata <= 0)
	{
		cout << "EROR ZARPLATA";
		return;
	}

	zarplata = m_zarplata;
}

void Povar::setFavoriteEat(string m_favoriteEat)
{
	if (size(m_favoriteEat) <= 0)
	{
		cout << "EROR EAT";
		return;
	}

	favoriteEat = m_favoriteEat;
}



int Povar::getZarplata()
{
	return zarplata;
}

string Povar::GetfavoriteEat()
{
	return favoriteEat;
}

Povar::Povar(int m_zarplata, string m_favoriteFood, string m_name) : Admin(m_name)
{
	zarplata = m_zarplata;
	favoriteEat = m_favoriteFood;
}

void Povar::showInfo()
{
	Admin::showInfo();
	cout << "Zarplata: " << zarplata << endl;
	cout << "Favorite eat: " << favoriteEat;
}

fstream& Povar::writeToFile(fstream& m_of)
{
	m_of << PersonType(COOK) << "\n";
	Admin::writeToFile(m_of);
	m_of << this->zarplata << "\n";
	m_of << this->favoriteEat << endl;
	return m_of;
}
