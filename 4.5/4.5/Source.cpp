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
		cout << "0.�����\n";
		cout << "1.������ ��������\n";
		cout << "2.������ ��������\n";
		cout << "3.�������� ��������\n";
		cout << "4.����������� ������ ��������\n";
		cout << "5.��������� �������� �� �����\n";
		cout << "6.�������� �������� � ����\n";
		cout << "7.����������� �������� �� id\n";
		cout << "->_";
		cin >> action;
		switch (action)
		{
		case 1: {
			Student temp;
			cout << "������ ���:";
			cin >> temp;
			list.Add(temp);
			break;
		}
		case 2: {
			Student studentChange;
			cout << "������ ����� ��������, ���� ����� �����:\n";
			cin >> studentChange;
			bool isList = list.ItemIsList(studentChange);
			if (isList)
			{
				cout << "�������� ��������. ������ ���� ��������:";
				Student newStudent;
				cin >> newStudent;
				list.Change(studentChange, newStudent);
			}
			//list.Add(temp);
			break;
		}
		case 4: {
			cout << "������ ��� ��������:\n";
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