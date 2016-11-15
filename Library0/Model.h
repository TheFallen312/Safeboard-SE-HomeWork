#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct User
{
	string UserName;
	int number_of_books;
	int book1_id;
	int book2_id;
	int book3_id;
	string book1_name;
	string book2_name;
	string book3_name;
	Date book1_date;
	Date book2_date;
	Date book3_date;
};

struct Book
{
	string book_name;
	int aval;
};

class Librarian
{
private:
	
	int number_of_users;
	int number_of_books;
	void Update_Users_List();
	void Update_Books_List();
public:
	Librarian();
	int GetNumber();
	int GetNumberOfBooks();
	User users[10];
	Book books[10];
	bool CheckUser(int un);
	bool CheckBook(int bn);
	void GiveBook(int un, int bn);
	bool HasBooks(int un);
	void RecieveBook(int un, int bn);
	string ExpiredList[10];
	void GetExpiredList();
	bool Expired(Date d, SYSTEMTIME st);
	int number_of_exp;
};