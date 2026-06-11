#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	vector<int> abc(3);

	cin >> abc.at(0) >> abc.at(1) >> abc.at(2);
	sort(abc.begin(),abc.end(),greater<int>());
		cout << ((abc.at(0) == abc.at(1) + abc.at(2)) ? "Yes" : "No") << endl;

}