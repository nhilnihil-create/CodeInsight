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
	str.insert(str.begin(), '-');
	int n = str.size()-1;
	while (n >= 0)
	{
		n -= 2;
		string s1 = str.substr(1, n / 2);
		string s2 = str.substr(n / 2+1, n / 2);
		if (str.substr(1, n / 2) == str.substr(n / 2+1, n / 2)) break;
	}
	cout << n;
}