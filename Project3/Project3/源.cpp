#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Name_pairs
{
private:
	vector<string> name;
	vector<double> age;
public:
	Name_pairs();
	friend ostream& operator<<(ostream& out, Name_pairs& np);
	int read_name(const string& s);
	int read_age(const double& a);
	int print();
	int sort();
	bool operator ==(const Name_pairs &np)const;
};

Name_pairs::Name_pairs()
{
}

ostream& operator<<(ostream& out, Name_pairs& np)
{
	out << np.print();
	return out;
}

int Name_pairs::read_name(const string& s)
{
	name.push_back(s);
	return 0;
}

int Name_pairs::read_age(const double& a)
{
	age.push_back(a);
	return 0;
}

int Name_pairs::print()
{
	for (unsigned int i = 0; i < name.size(); i++)
	{
		cout << "����Ϊ��" << name[i] << " ����Ϊ��" << age[i] << endl;
	}
	return 0;
}

int Name_pairs::sort()
{
	string flag;
	double temp = 0;
	for (unsigned int i = 0; i < name.size(); i++)
	{
		for (unsigned int j = 0; j < name.size(); j++)
		{
			if (name[i][0] < name[j][0])
			{
				flag = name[i];
				name[i] = name[j];
				name[j] = flag;
				temp = age[i];
				age[i] = age[j];
				age[j] = temp;
			}
		}
	}
	return 0;
}

bool Name_pairs::operator==(const Name_pairs &np)const
{
	if (this->age == np.age&&this->name == np.name)
	{
		return true;
	}
	return false;
}

int main()
{
	string name;
	double age = 0;
	Name_pairs list1;
	char ch;
	cout << "���������������Լ�����";
	while(cin>>ch)
	{
		if (ch == 'q')
		{
			break;
		}
		else
		{
			cout << "���������֣�";
			cin >> name;
			list1.read_name(name);
			cout << "���������䣺";
			cin >> age;
			list1.read_age(age);
			cout << "���������������Լ���������q���˳���";
		}
	}
	list1.sort();
	cout << list1;
	system ("pause");
	return 0;
}