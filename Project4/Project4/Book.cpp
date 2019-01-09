#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
	enum Genre { fiction, nonfiction, periodical, biography, children };
	Book(string& isbn, string& name, string& author, int& date,Genre gen);		//构造函数录入书的ISBN号、书名、作者、版权日期和类型
	Book();			//空构造函数
	string read_ISBN()const;		//读取ISBN号
	string read_bookname()const;	//读取书名
	string read_aurhor()const;		//读取作者名
	int read_copydate()const;		//读取版权日期
	void borrow_book();				//借书
	void return_book();				//还书
	bool isbn_valid(const string& isbn);		//确定ISBN是否为有效的ISBN码
	bool operator==(const Book& a);
	bool operator!=(const Book& a);
	friend ostream& operator<<(ostream& out,const Book& a);
	~Book();

private:
	string ISBN_number;		//书的ISBN号
	string Book_name;		//书名
	string Author;			//作者
	int Copyright_date;		//版权日期
	Genre genre;			//类型
	bool Borrowed = false;	//是否借出(默认为否）
};

Book::Book(string& isbn, string& name, string& author, int& date, Genre gen)
{
	while (!isbn_valid(isbn))
	{
		cout << "输入的ISBN号有误 不是合法的数据 请重新输入：";
		cin >> isbn;
	}
	ISBN_number = isbn;
	Book_name = name;
	Author = author;
	Copyright_date = date;
}

Book::Book()
{
}

string Book::read_ISBN()const
{
	return ISBN_number;
}

string Book::read_bookname()const
{
	return Book_name;
}

string Book::read_aurhor()const
{
	return Author;
}

int Book::read_copydate()const
{
	return Copyright_date;
}

void Book::borrow_book()
{
	if (!Borrowed)
	{
		Borrowed = true;
		cout << "借书成功";
	}
	else
	{
		cout << "此书已被借走";
	}
}

void Book::return_book()
{
	if (Borrowed)
	{
		Borrowed = false;
	}
	else
	{
		cout << "error!";
	}
}

bool Book::isbn_valid(const string& isbn)
{
	if (isbn.length() > 4)
	{
		cout << "数据错误超出上限";
		return false;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i < 3)
		{
			if (isbn[i]<'0'&&isbn[i]>'9')
			{
				return false;
			}
		}
		else if (i == 3)
		{
			if ((isbn[i] > '0'&&isbn[i] < '9') || (isbn[i] > 'A'&&isbn[i] < 'Z') || (isbn[i] > 'a'&&isbn[i] < 'z'))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Book::operator==(const Book& a)
{
	return (this->ISBN_number == a.ISBN_number);
}

bool Book::operator!=(const Book& a)
{
	return !(*this == a);
}


Book::~Book()
{
}

ostream& operator<<(ostream & os, const Book & a)
{
	os<<"书名为："<<a.Book_name<<endl<<"作者为："<<a.Author<<endl<<"ISBN号："<<a.ISBN_number<<endl;
	return os;
}
