#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	string	a;	cin >> a;
	int		j = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a.at(i) != a.at(j))
		{
			cout << "No" << endl;
			goto OUT;
		}
		j++;
	}
	cout << "Yes" << endl;
	OUT:
	return 0;
}