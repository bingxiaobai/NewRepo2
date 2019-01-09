#include <iostream>
#include <string>
using namespace std;

class Patron
{
public:
	Patron(string na, int ID, int balance);		//���캯��
	Patron();
	string read_name()const;		//��ȡ����������
	int read_ID()const;				//��ȡͼ��֤��
	int read_balance()const;		//��ȡ���
	int set_balance();				//���ý���Ѳ��۷�
	bool is_arrears(const Patron& a);//�ж��Ƿ�Ƿ��
	~Patron();

private:
	string Name;		//����������
	int Card_ID;		//ͼ��֤��
	int Balance;		//���
};

Patron::Patron(string na, int ID, int balance)		//���캯��
{
	Name = na;
	Card_ID = ID;
	Balance = balance;
}

Patron::Patron()
{
}

string Patron::read_name()const		//��ȡ����������
{
	return Name;
}

int Patron::read_ID()const			//��ȡͼ��֤��
{
	return Card_ID;
}

int Patron::read_balance()const		//��ȡ���
{
	return Balance;
}

int Patron::set_balance()			//���ý���Ѳ��۷�
{
	int num;
	cout << "��������εĽ���ѣ�";
	cin >> num;
	Balance = Balance - num;
	if (is_arrears(*this))
	{
		cout << "��Ƿ��" << -Balance << "Ԫ���뾡���ֵ��" << endl;
	}
	else
	{
		cout << "�۷���ɡ�" << endl;
	}
	return 0;
}

bool Patron::is_arrears(const Patron& a)		//����Ƿ�Ƿ��
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