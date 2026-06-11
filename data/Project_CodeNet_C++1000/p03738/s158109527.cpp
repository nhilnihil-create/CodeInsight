#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 7;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	if (str1 == str2)cout << "EQUAL";
	else if (str1.size() > str2.size())cout << "GREATER";
	else if (str1.size() < str2.size())cout << "LESS";
	else
	{
		for (int i = 0; i <= max(str1.size() - 1, str2.size() - 1); i++)
		{
			int a = str1[i] - '0';
			int b = str2[i] - '0';
			if (a == b)continue;
			if (i > str2.size()-1)
			{
				cout << "GREATER"; break;
			}
			if (i > str1.size()-1)
			{
				cout << "LESS"; break;
			}
			if (a > b) {
				cout << "GREATER"; break;
			}
			else
			{
				cout << "LESS"; break;
			}
		}
	}
}