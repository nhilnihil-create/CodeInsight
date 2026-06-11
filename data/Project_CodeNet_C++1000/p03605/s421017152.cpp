#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	string	a;	cin >> a;
	for (auto &i : a)
	{
		if (i == '9')
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}