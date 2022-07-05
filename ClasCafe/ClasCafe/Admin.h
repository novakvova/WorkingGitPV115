#pragma once
#include <iostream>

enum PersonType
{
	COOK = 0,   //повар
	WAITER = 1  //офіціант
};

using namespace std;

class Admin
{
private:
	string name;
	int buyPrulad;
public:
	Admin();
	string getName();
	int getPrulad();

	void setName(string m_name);
	void setPrulad(int m_prulad);
	virtual fstream& writeToFile(fstream& of);
	virtual void showInfo();

protected:
	Admin(string m_name);
};

