#include <iostream>
#include <string>
using namespace std;

class Patron
{
public:
	Patron(string na, int ID, int balance);		//构造函数
	Patron();
	string read_name()const;		//读取借书人姓名
	int read_ID()const;				//读取图书证号
	int read_balance()const;		//读取余额
	int set_balance();				//设置借书费并扣费
	bool is_arrears(const Patron& a);//判断是否欠费
	~Patron();

private:
	string Name;		//借书人姓名
	int Card_ID;		//图书证号
	int Balance;		//余额
};

Patron::Patron(string na, int ID, int balance)		//构造函数
{
	Name = na;
	Card_ID = ID;
	Balance = balance;
}

Patron::Patron()
{
}

string Patron::read_name()const		//读取借书人姓名
{
	return Name;
}

int Patron::read_ID()const			//读取图书证号
{
	return Card_ID;
}

int Patron::read_balance()const		//读取余额
{
	return Balance;
}

int Patron::set_balance()			//设置借书费并扣费
{
	int num;
	cout << "请输入这次的借书费：";
	cin >> num;
	Balance = Balance - num;
	if (is_arrears(*this))
	{
		cout << "已欠费" << -Balance << "元，请尽快充值。" << endl;
	}
	else
	{
		cout << "扣费完成。" << endl;
	}
	return 0;
}

bool Patron::is_arrears(const Patron& a)		//检测是否欠费
{
	if (a.Balance < 0)
	{
		return true;
	}
	return false;
}

Patron::~Patron()
{
}