#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Model.h"


using namespace std;

//функции view
void show_menu()
{
	cout << "[1] Show books" << endl;
	cout << "[2] Show users" << endl;
	cout << "[3] Give book" << endl;
	cout << "[4] Recieve book" << endl;
	cout << "[5] Show users with expired books" << endl;
	cout << "[6] Exit" << endl;
	cout << "Input:";
}

void show_user_list(User u[],int n)
{
	
	for (int i = 0; i < n; i++)
	{
		cout <<"["<<i<<"] " << u[i].UserName << endl;
	}

}
void show_books_list(Book b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i << "] " << b[i].book_name << endl;
	}
}
void show_user_books(User a)
{

	cout << "[1] " << a.book1_name << endl;
	cout << "[2] " << a.book2_name << endl;
	cout << "[3] " << a.book3_name << endl;

}

int main()
{

	SYSTEMTIME s;
	GetLocalTime(&s);
	bool Exit = false;
	int nos;
	cout << "Number of source:";
	cin >> nos;
	Librarian L(nos);
	while (!Exit){

		system("cls");
		show_menu();

		int m;

		// controller
		cin >> m;
		cout << endl;
		system("cls");
		int a = 0;
		int b = 0;
		switch (m)
		{
		case 1:
			b = L.GetNumberOfBooks();
			show_books_list(L.books, b);
			system("Pause");
			break;
		case 2:
			cout << "Users:" << endl;
			a = L.GetNumber();
			show_user_list(L.users, a);
			system("Pause");
			break;
		case 3:
			a = L.GetNumber();
			show_user_list(L.users, a);
			a = 0;
			cout << "Choose user:";
			cin >> a;
			if (L.CheckUser(a))
			{
				system("cls");
				b = L.GetNumberOfBooks();
				show_books_list(L.books, b);
				cout << "Choose book:";
				cin >> b;
				if (L.CheckBook(b))
					L.GiveBook(a, b);
				else
					cout << "Choose another book!";

			}
			else
			{
				cout << "You can't take more than 3 books!";
			}
			system("Pause");
			break;
		case 4:
			a = L.GetNumber();
			show_user_list(L.users, a);
			a = 0;
			b = 0;
			cout << "Choose user:";
			cin >> a;
			system("cls");
			if (L.HasBooks(a))
			{
				show_user_books(L.users[a]);
				cout << "Choose book:";
				cin >> b;
				L.RecieveBook(a, b);

			}
			else
			{
				cout << "No books!";
			}
			system("Pause");
			break;
		case 5:
			system("cls");
			L.GetExpiredList();
			for (a = 0; a < L.number_of_exp; a++)
			{
				cout << L.ExpiredList[a] << endl;
			}
			system("Pause");
			break;
		case 6:
			Exit = true;
			break;
		}

	}
	return 0;
}
