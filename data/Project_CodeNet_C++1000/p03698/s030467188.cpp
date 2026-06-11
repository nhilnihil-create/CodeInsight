#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	map<char, int> mp;
	for (auto &&c : s)
	{
		mp[c]++;
	}

	for (auto &&p : mp)
	{
		if (1 < p.second)
		{
			cout << "no" << endl;
			return 0;
		}
	}

	cout << "yes" << endl;

	return 0;
}