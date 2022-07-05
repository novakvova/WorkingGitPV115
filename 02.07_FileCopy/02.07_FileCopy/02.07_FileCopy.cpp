#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <direct.h>
#include <windows.h>
#include <filesystem>
#include <cstring>

int counter;
using namespace std;
void copyFile(char* name2, char* name1);

int main()
{
    char name1[80]{};
    char name2[80]{};

   
    while (true)
    {
        system("CLS");
        char menu;
        cout << "1. Copy file\n2. Exit\n --> ";
        cin >> menu;
        if (menu == '2') {
            break;
        }
        else {
           
            copyFile(name2, name1);
        }
    }
    
    return 0;
}
void copyFile(char* name2, char* name1)
{
    _mkdir("images");
    char source[50] = "images\\";
    counter++;
    char num_char[10]{};
    sprintf(num_char, "%d", counter);
    strcat(num_char, ".jpg");
    strcat(source, num_char);
    cout << "Enter source to file : ";
    cin >> name2;
    ofstream fileOut(source, ios::binary);
    ifstream fileIn(name2, ios::binary);

    char byte[1];
    while (fileIn.read(byte, 1)) {
        fileOut.write(byte, 1);
    }
}