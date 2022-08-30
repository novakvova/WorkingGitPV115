#include<iostream>
#include "Doubly.h"
#include "Student.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include<Windows.h>
using namespace std;
using namespace cv;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	/*cv::Mat img = cv::imread("remove-bg.webp");
	namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
	cv::imshow("First OpenCV Application", img);
	cv::moveWindow("First OpenCV Application", 0, 45);
	cv::waitKey(0);
	cv::destroyAllWindows();*/

	Doubly<Student> list;
	int action = 0;
	do
	{
		cout << "0.Вихід\n";
		cout << "1.Додати студента\n";
		cout << "2.Змінити студента\n";
		cout << "3.Видалити студента\n";
		cout << "4.Переглянути список студентів\n";
		cout << "5.Загрузити студентів із файла\n";
		cout << "6.Зберегти студентів у файл\n";
		cout << "7.Переглянути студента по id\n";
		cout << "->_";
		cin >> action;
		switch (action)
		{
		case 1: {
			Student temp;
			cout << "Вкажіть дані:";
			cin >> temp;
			list.Add(temp);
			break;
		}
		case 2: {
			Student studentChange;
			cout << "Вкажіть назву елемента, який треба мінять:\n";
			cin >> studentChange;
			bool isList = list.ItemIsList(studentChange);
			if (isList)
			{
				cout << "Студента знайдено. Вкажіть нове значення:";
				Student newStudent;
				cin >> newStudent;
				list.Change(studentChange, newStudent);
			}
			//list.Add(temp);
			break;
		}
		case 4: {
			cout << "Список усіх елементів:\n";
			list.ShowList();
			break;
		}

		case 5: {
			list.ReadDataFile("mydata.txt");
		}

		case 6: {
			list.SaveToFile("mydata.txt");
		}
		case 7: {
			string idst;
			cout << "Enter student id:";
			cin >> idst;
			Student idS(idst);

			list.ShowListId(idS);
		}
		}



	} while (action != 0);


	return 0;
}