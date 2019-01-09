#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> s{ 10,20,11,23,44,54,23,55,16,72 };
vector<int> n(5, 0);

int main()
{
	auto mid = s.begin() + s.size() / 2;
	n.clear();
	for (auto it = s.begin(); it != mid; it++)
	{
		int temp = 0;
		auto leng = it - s.begin();
		auto anoth = s.end() - 1 - leng;
		temp = *it + *anoth;
		n.push_back(temp);
	}
	for (auto it = n.begin(); it != n.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}