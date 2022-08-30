#pragma once
#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include<Windows.h>
using namespace std;
using namespace cv;
#include<fstream>
#include<ctime>;
#include <cstdio>
#include <direct.h>
using namespace std;
class Student
{
private:
	string id; //ідентифікаторі, або номер по порядку
	string name;
	string phone;
	string image;
	int age;




	string RandomFileName(string ex)
	{
		srand(time(0));
		char dictionary[52];// { 'a', 'b', 'c', 'd'};

		char ch = 'Z'; // a - 97 z-122, A-65 Z-90
		//cout << (int)ch;
		int k = 0;
		for (int i = 65; i <= 90; i++)
		{
			dictionary[k++] = (char)i;
			//cout << (char)i << "\n";
		}
		for (int i = 97; i <= 122; i++)
		{
			dictionary[k++] = (char)i;
			//cout << (char)i << "\n";
		}
		string fileName = "";
		while (true)
		{
			for (int i = 0; i < 9; i++)
			{
				int r = rand() % 52;
				fileName += dictionary[r];
			}
			fileName += ex;
			ifstream in(fileName);
			if (!in.is_open())
				break;
			in.close();
		}
		return fileName;
	}

public:
	Student() {
		this->id = "";
		this->name = "";
		this->phone = "";
		this->image = "";
		this->age = 18;
	}
	Student(const char* id, const char* name, const char* phone, char* image, int age)
	{
		this->id = id;
		this->name = name;
		this->phone = phone;
		this->image = image;
		this->age = age;
	}

	Student(const Student& student)
	{
		this->id = student.id;
		this->name = student.name;
		this->age = student.age;
		this->phone = student.phone;
		this->image = student.image;
	}
	Student(const string id)
	{
		this->id = id;
	}

	bool operator>(const Student& student)
	{
		if (this->name > student.name)
			return true;
		return false;
	}

	bool operator==(const Student& student)
	{
		if (this->id == student.id)
			return true;
		return false;
	}

	/*bool operator==(const Student& student)
	{
		if (this->name == student.name)
			return true;
		return false;
	}*/
	bool operator!=(const Student& student)
	{
		if (this->name != student.name)
			return true;
		return false;
	}

	Student& operator=(const Student& student)
	{
		if (this == &student)
			return *this;
		if (!student.id.empty())
			this->id = student.id;
		if (!student.name.empty())
			this->name = student.name;
		//this->image = student.image;
		if (!student.phone.empty())
			this->phone = student.phone;
		if (!student.image.empty())
			this->image = student.image;
		this->age = student.age;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Student& student)
	{

		out << student.id << "\t" << student.name << "\t" << student.phone << "\t"
			<< student.image << "\t" << student.age;

		cv::Mat img = cv::imread(student.image);
		namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
		cv::imshow("First OpenCV Application", img);
		cv::moveWindow("First OpenCV Application", 0, 45);
		cv::waitKey(0);
		cv::destroyAllWindows();

		return out;
	}

	friend istream& operator>>(istream& in, Student& student)
	{
		in.seekg(0);
		char tmp[100];

		cout << "Enter student Id\n";
		in.getline(tmp, 100, '\n');
		string str = tmp;
		if (!str.empty())
			student.id = tmp;

		cout << "Enter student Name\n";
		in.getline(tmp, 100, '\n');
		str = tmp;
		if (!str.empty())
			student.name = tmp;


		cout << "Enter student Phone\n";
		in.getline(tmp, 100, '\n');
		str = tmp;
		if (!str.empty())
			student.phone = tmp;


		cout << "Enter student Image Path\n";
		in.getline(tmp, 100, '\n');
		str = tmp;
		if (!str.empty())
		{
			string fileName = student.RandomFileName(".jpg");
			student.image = "images\\" + fileName;
			_mkdir("images");
			ofstream out(student.image, ios::binary);
			ifstream reader(tmp, ios::binary);
			char byte[1];
			while (reader.read(byte, 1))
			{
				//cout << byte << "\n";
				out.write(byte, 1);
			}
			reader.close();
			out.close();
		}

		cout << "Enter student Age\n";
		in >> student.age;
		return in;
	}


	friend ofstream& operator<<(ofstream& out, const Student& student)
	{
		out << student.id << "\n"
			<< student.name << "\n" << student.phone
			<< "\n" << student.image
			<< "\n" << student.age;
		return out;
	}
	friend ifstream& operator>>(ifstream& in, Student& student)
	{
		char tmp[100];
		in.getline(tmp, 100, '\n');
		student.id = tmp;
		in.getline(tmp, 100, '\n');
		student.name = tmp;
		in.getline(tmp, 100, '\n');
		student.phone = tmp;
		in.getline(tmp, 100, '\n');
		student.image = tmp;
		in >> student.age;
		in.getline(tmp, 100, '\n');
		return in;
	}


};