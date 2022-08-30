#pragma once
#include<iostream>
#include<fstream>



#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include<Windows.h>
using namespace std;
using namespace cv;


template <typename T> class Doubly
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};
	Node* head;

public:
	Doubly() {
		head = NULL;
	}
	void Add(T data)
	{
		if (head == NULL)   //Якщо список пустий, елемент потрапляє на початок
		{
			Node* myNode = new Node;
			myNode->data = data;
			myNode->prev = myNode->next = NULL;
			head = myNode;
		}
		else { //Якщо елемент перший уже є, тоді переміщаємо у кінець
			Node* temp = head; //Temp - вказує на перший елемент
			while (temp->next != NULL) //Якщо temp уже у кінці
			{
				temp = temp->next; //переміщаємо на наступний елемент
			}
			Node* newNode = new Node();
			newNode->data = data;
			newNode->prev = temp;//Зберігаємо вказівник на опередній елемент
			temp->next = newNode; //У кінець додаємо новий елемент
		}
	}



	void SaveToFile(const char* filePath)
	{
		ofstream out(filePath);
		Node* temp = head; //Temp - вказує на перший елемент
		while (temp != NULL) //Якщо temp уже у кінці
		{
			out << temp->data << "\n";
			temp = temp->next; //переміщаємо на наступний елемент
		}
		out.close();
	}


	void ReadDataFile(const char* filePath)
	{
		ifstream in(filePath);

		while (!in.eof())
		{
			T tmp;
			in >> tmp;
			if (in.eof())
				break;
			this->Add(tmp);
		}
		in.close();
	}
	void ShowList()
	{
		Node* temp = head; //Temp - вказує на перший елемент
		while (temp != NULL) //Якщо temp уже у кінці
		{
			cout << temp->data << "\n";
			temp = temp->next; //переміщаємо на наступний елемент
		}
	}

	bool ItemIsList(T data)
	{
		Node* temp = head; //Temp - вказує на перший елемент
		while (temp != NULL) //Якщо temp уже у кінці
		{
			if (data == temp->data)
				return true;
			temp = temp->next; //переміщаємо на наступний елемент
		}
		return false;
	}
	void Change(T oldData, T newData)
	{
		Node* temp = head; //Temp - вказує на перший елемент
		while (temp != NULL) //Якщо temp уже у кінці
		{
			if (oldData == temp->data)
				temp->data = newData;
			temp = temp->next; //переміщаємо на наступний елемент
		}
	}
	void ShowListId(T data)
	{
		Node* temp = head; //Temp - вказує на перший елемент
		while (temp != NULL) //Якщо temp уже у кінці
		{
			if (temp->data == data)
				cout << temp->data;
			temp = temp->next; //переміщаємо на наступний елемент
		}

	}
};
