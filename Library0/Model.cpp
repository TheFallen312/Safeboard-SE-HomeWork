#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Model.h"

Librarian::Librarian()
{

	ifstream F;
	F.open("users.txt", ios::in);
	int i = 0;
	while (!F.eof())
	{
		F >> users[i].UserName >> users[i].number_of_books;
		F >> users[i].book1_id >> users[i].book1_name >> users[i].book1_date.day >> users[i].book1_date.month >> users[i].book1_date.year;
		F >> users[i].book2_id >> users[i].book2_name >> users[i].book2_date.day >> users[i].book2_date.month >> users[i].book2_date.year;
		F >> users[i].book3_id >> users[i].book3_name >> users[i].book3_date.day >> users[i].book3_date.month >> users[i].book3_date.year;
		i++;
	};
	number_of_users = i-1;
	F.close();
	F.open("books.txt", ios::in);
	i = 0;
	while (!F.eof())
	{
		F >> books[i].book_name >> books[i].aval;
		i++;
	};
	number_of_books = i-1;
	F.close();

}

Librarian::Librarian(int s)
{
	ifstream F;
	F.open("users.txt", ios::in);
	int i = 0;
	while (!F.eof())
	{
		F >> users[i].UserName >> users[i].number_of_books;
		F >> users[i].book1_id >> users[i].book1_name >> users[i].book1_date.day >> users[i].book1_date.month >> users[i].book1_date.year;
		F >> users[i].book2_id >> users[i].book2_name >> users[i].book2_date.day >> users[i].book2_date.month >> users[i].book2_date.year;
		F >> users[i].book3_id >> users[i].book3_name >> users[i].book3_date.day >> users[i].book3_date.month >> users[i].book3_date.year;
		i++;
	};
	number_of_users = i - 1;
	F.close();
	i = 0;
	switch (s)
	{

	case 1:
		F.open("books.txt", ios::in);
		while (!F.eof())
		{
			F >> books[i].book_name >> books[i].aval;
			i++;
		};
		number_of_books = i - 1;
		F.close();
		break;
	case 2:
		F.open("books2.txt", ios::in);
		while (!F.eof())
		{
			F >> books[i].book_name >> books[i].aval;
			i++;
		};
		number_of_books = i - 1;
		F.close();
		break;
	case 3:
		F.open("books3.txt", ios::in);
		while (!F.eof())
		{
			F >> books[i].book_name >> books[i].aval;
			i++;
		};
		number_of_books = i - 1;
		F.close();
		break;
	}
}

int Librarian::GetNumber()
{
	return number_of_users;
}

void Librarian::Update_Users_List()
{
	ofstream F;
	F.open("users.txt", ios::out);
	for (int i = 0; i < number_of_users; i++)
	{
		F << users[i].UserName << " " << users[i].number_of_books << " " << endl;
		F << users[i].book1_id << " " << users[i].book1_name << " " << users[i].book1_date.day << " " << users[i].book1_date.month << " " << users[i].book1_date.year << endl;;
		F << users[i].book2_id << " " << users[i].book2_name << " " << users[i].book2_date.day << " " << users[i].book2_date.month << " " << users[i].book2_date.year << endl;;
		F << users[i].book3_id << " " << users[i].book3_name << " " << users[i].book3_date.day << " " << users[i].book3_date.month << " " << users[i].book3_date.year << endl;

	}

}

int Librarian::GetNumberOfBooks()
{
	return number_of_books;
}

void Librarian::Update_Books_List()
{
	ofstream F;
	F.open("books.txt", ios::out);
	for (int i = 0; i < number_of_books; i++)
	{
		F << books[i].book_name << " " << books[i].aval << endl;;
	}
}

bool Librarian::CheckUser(int un)
{
	if (users[un].number_of_books < 3)
		return true;
	else
	{
		return false;
	}


}

bool Librarian::CheckBook(int bn)
{
	if (books[bn].aval == 1)
		return true;
	else
	{
		return false;
	}

}
bool Librarian::HasBooks(int un)
{
	if (users[un].number_of_books > 0)
		return true;
	else
	{
		return false;
	}
}

void Librarian::GiveBook(int un, int bn)
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	books[bn].aval = 0;
	if (users[un].book1_name == "Free")
	{
		users[un].book1_name = books[bn].book_name;
		users[un].book1_date.day = s.wDay;
		users[un].book1_date.month = s.wMonth;
		users[un].book1_date.year = s.wYear;
	}
	else if (users[un].book2_name == "Free")	
	{
		users[un].book2_name = books[bn].book_name;
		users[un].book2_date.day = s.wDay;
		users[un].book2_date.month = s.wMonth;
		users[un].book2_date.year = s.wYear;
	}
	else if (users[un].book3_name == "Free")
	{
		users[un].book3_name = books[bn].book_name;
		users[un].book3_date.day = s.wDay;
		users[un].book3_date.month = s.wMonth;
		users[un].book3_date.year = s.wYear;
	}
	users[un].number_of_books++;
	Update_Users_List();
	Update_Books_List();

}

void Librarian::RecieveBook(int un, int bn)
{
	switch (bn)
	{
	case 1:
		books[users[un].book1_id].aval = 1;
		users[un].book1_id = -1;
		users[un].book1_name = "Free";
		users[un].book1_date.day = 0;
		users[un].book1_date.month = 0;
		users[un].book1_date.year = 0;
		users[un].number_of_books--;
		break;
	case 2:
		books[users[un].book2_id].aval = 1;
		users[un].book2_id = -1;
		users[un].book2_name = "Free";
		users[un].book2_date.day = 0;
		users[un].book2_date.month = 0;
		users[un].book2_date.year = 0;
		users[un].number_of_books--;
		break;
	case 3:
		books[users[un].book3_id].aval = 1;
		users[un].book3_id = -1;
		users[un].book3_name = "Free";
		users[un].book3_date.day = 0;
		users[un].book3_date.month = 0;
		users[un].book3_date.year = 0;
		users[un].number_of_books--;
		break;
	default:
		break;
	}
	Update_Users_List();
	Update_Books_List();

}

bool Librarian::Expired(Date d, SYSTEMTIME st)
{
	if (st.wYear > d.year)
		return true;
	else if (st.wMonth>d.month)
	{
		if (st.wMonth - d.month > 1)
			return true;
		else if (st.wDay > d.day)
			return true;
		else
			return false;
	}
	else
		return false;

}

void Librarian::GetExpiredList()
{
	number_of_exp = 0;
	SYSTEMTIME s;
	GetLocalTime(&s);
	for (int i = 0; i < number_of_users; i++)
	{
		int flag = 0;
		if (users[i].book1_id>=0)
			if (Expired(users[i].book1_date,s))
			{
				ExpiredList[number_of_exp] = users[i].UserName;
				number_of_exp++;
				flag = 1;
			}
		if ((users[i].book2_id >= 0)&&(flag ==0))
			if (Expired(users[i].book2_date, s))
			{
				ExpiredList[number_of_exp] = users[i].UserName;
				number_of_exp++;
				flag = 1;
			}
		if ((users[i].book3_id >= 0) && (flag == 0))
			if (Expired(users[i].book3_date, s))
			{
				ExpiredList[number_of_exp] = users[i].UserName;
				number_of_exp++;
				flag = 1;
			}
	}

}


