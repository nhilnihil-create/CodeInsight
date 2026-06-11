#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	vector<string> siritori(3);
	for (int i = 0; i < 3; i++)
		cin >> siritori.at(i);
	if (siritori.at(0).at(siritori.at(0).size() - 1) == siritori.at(1).at(0))
		cout << (siritori.at(1).at(siritori.at(1).size() - 1) == siritori.at(2).at(0) ? "YES" : "NO") << endl;
	else
		cout << "NO" << endl;
}