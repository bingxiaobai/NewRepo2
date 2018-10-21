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
	int read_name(const string& s);
	int read_age(const double& a);
	int print();
	int sort();
};

Name_pairs::Name_pairs()
{
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
		cout << "姓名为：" << name[i] << " 年龄为：" << age[i] << endl;
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

int main()
{
	string name;
	double age = 0;
	Name_pairs list1;
	char ch;
	cout << "请输入任意数字以继续：";
	while(cin>>ch)
	{
		if (ch == 'q')
		{
			break;
		}
		else
		{
			cout << "请输入名字：";
			cin >> name;
			list1.read_name(name);
			cout << "请输入年龄：";
			cin >> age;
			list1.read_age(age);
			cout << "请输入任意数字以继续或输入q来退出：";
		}
	}
	list1.sort();
	list1.print();
	system ("pause");
	return 0;
}