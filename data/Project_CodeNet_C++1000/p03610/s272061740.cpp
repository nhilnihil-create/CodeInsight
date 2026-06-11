#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 7;
int lst[Max];

int main()
{
	string str;
	cin >> str;
	int n = str.size(), g = 1;
	str.insert(str.begin(), '-');
	while (g <= n)
	{
		cout << str[g];
		g += 2;
	}
}