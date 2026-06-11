#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n)
using namespace std;
int main()
{
	MaRiaMa;
	set<char> c;
	int k = 0;
	string s;
	set<char> p;
	cin >> s;
	for (int i = 0; i < 26; i++)
	{
		c.emplace(char(97+i));
	}
	for (int i = 0; i < s.size(); i++)
	{
		p.emplace(s[i]);
	}
	auto l = c.begin();
	for (auto it = p.begin(); l != c.end(); it++)
	{
		if (it != p.end())
		{
			if (*l != *it)
			{
				cout << *l;
				return 0;
			}
			l++;
		}
		else
		{
			cout << *l;
			return 0;
		}
	}
	cout << "None";
}



