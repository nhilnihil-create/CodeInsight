#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	vector<string>	letter(3);
	for (int i = 0; i < 3; i++)
		cin >> letter.at(i);
	for (auto &i : letter)
		cout << char(i.at(0) - 32);
	cout << endl;
}