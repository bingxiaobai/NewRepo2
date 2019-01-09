#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
	enum Genre { fiction, nonfiction, periodical, biography, children };
	Book(string& isbn, string& name, string& author, int& date,Genre gen);		//���캯��¼�����ISBN�š����������ߡ���Ȩ���ں�����
	Book();			//�չ��캯��
	string read_ISBN()const;		//��ȡISBN��
	string read_bookname()const;	//��ȡ����
	string read_aurhor()const;		//��ȡ������
	int read_copydate()const;		//��ȡ��Ȩ����
	void borrow_book();				//����
	void return_book();				//����
	bool isbn_valid(const string& isbn);		//ȷ��ISBN�Ƿ�Ϊ��Ч��ISBN��
	bool operator==(const Book& a);
	bool operator!=(const Book& a);
	friend ostream& operator<<(ostream& out,const Book& a);
	~Book();

private:
	string ISBN_number;		//���ISBN��
	string Book_name;		//����
	string Author;			//����
	int Copyright_date;		//��Ȩ����
	Genre genre;			//����
	bool Borrowed = false;	//�Ƿ���(Ĭ��Ϊ��
};

Book::Book(string& isbn, string& name, string& author, int& date, Genre gen)
{
	while (!isbn_valid(isbn))
	{
		cout << "�����ISBN������ ���ǺϷ������� ���������룺";
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
		cout << "����ɹ�";
	}
	else
	{
		cout << "�����ѱ�����";
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
		cout << "���ݴ��󳬳�����";
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
	os<<"����Ϊ��"<<a.Book_name<<endl<<"����Ϊ��"<<a.Author<<endl<<"ISBN�ţ�"<<a.ISBN_number<<endl;
	return os;
}
