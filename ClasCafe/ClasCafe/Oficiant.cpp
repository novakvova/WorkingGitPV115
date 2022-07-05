#include "oficiant.h"
#include <fstream>
using namespace std;

Oficiant::Oficiant()
{
	zakazov = 0;
	likeAnimal = "none";
}

Oficiant::Oficiant(int m_zakazov, string likeAnim, string m_name) : Admin(m_name)
{
	zakazov = m_zakazov;
	likeAnimal = likeAnim;
	
}



void Oficiant::setZakazov(int m_zakazov)
{
	if (m_zakazov <= 0)
	{
		cout << "EROR ZARPLATA";
		return;
	}

	zakazov = m_zakazov;
}

void Oficiant::setlikeAnimal(string m_favoriteAnimal)
{
	if (size(m_favoriteAnimal) <= 0)
	{
		cout << "EROR EAT";
		return;
	}

	likeAnimal = m_favoriteAnimal;
}



int Oficiant::getZakazov()
{
	return zakazov;
}

string Oficiant::GetfavoriteAnimal()
{
	return likeAnimal;
}

void Oficiant::showInfo()
{
	Admin::showInfo();
	cout << "Zakazov: " << zakazov << endl;
	cout << "Like animal: " << likeAnimal;
}

fstream& Oficiant::writeToFile(fstream& m_of)
{
	m_of << PersonType(WAITER) << "\n";
	Admin::writeToFile(m_of);
	m_of << this->zakazov << "\n";
	m_of << this->likeAnimal << endl;
	return m_of;
}
