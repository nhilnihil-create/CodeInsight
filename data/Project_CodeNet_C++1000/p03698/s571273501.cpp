#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 7;
string lst[Max];

int main()
{
	map<char, int> ma;
	string str;
	cin >> str;
	int f = 0;
	for (int i = 0; i <= str.size() - 1; i++)
	{
		if (ma[str[i]])
		{
			f = 1; break;
		}
		ma[str[i]]++;
	}
	if (f)cout << "no";
	else cout << "yes";
}