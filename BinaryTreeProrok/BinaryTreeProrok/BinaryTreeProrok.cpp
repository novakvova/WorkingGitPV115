#include<iostream>
using namespace std;
#include<Windows.h>
#include "BST.h"
#include "Student.h"

//Á³íàðíå äåðåâî



int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    BST<Student> b, * root = NULL;

    Student ivan("Іван Петрович Batkovich", "098 876 54 34", 18);

    Student ivan1("Іван Петрович", "098 876 54 34", 28);
    
    Student ivan2("Іван Петрович 2", "098 876 54 34", 15);
   
    Student ivan3("Іван Петрович 3", "098 876 54 34", 28);
    
    Student ivan4("Іван Петрович 4", "098 876 54 34", 28);

    Student key("Іван Петрович 2", "098 876 54 34", 18);
    int counter = 0;

    root = b.Insert(root, ivan); //ðîáèìî ñòîâáóê
    b.Insert(root, ivan1);
    b.Insert(root, ivan4);
    b.Insert(root, ivan2);
    b.Insert(root, ivan3);

    b.search(root, key,counter);
    cout << "Counter : " << counter << endl;
    //âèâîäèìî íà åêðàí óñå äðåðåâî

    b.Inorder(root);
    return 0;
}
