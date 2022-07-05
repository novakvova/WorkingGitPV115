#include "Admin.h"
#include <fstream>

Admin::Admin()
{
    name = "no name";
    buyPrulad = 0;
}

string Admin::getName()
{
    return name;
}

int Admin::getPrulad()
{
    return buyPrulad;
}

void Admin::setName(string m_name)
{
    if (size(m_name) > 0)
    {
        cout << "EROR NAME";
        return;
    }

    name = m_name;
}

void Admin::setPrulad(int m_prulad)
{
    buyPrulad = m_prulad;
}

void Admin::showInfo()
{
    cout << "Name: " << name << endl;
}

Admin::Admin(string m_name)
{
    name = m_name;
}

fstream& Admin::writeToFile(fstream& m_of)
{
    m_of << this->name << "\n";
    return m_of;
}

