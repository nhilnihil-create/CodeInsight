#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	char	a, b;

	cin >> a >> b;

	if (a == 'H')
		cout << (b == 'H' ? "H" : "D") << endl;
	else
		cout << (b == 'H' ? "D" : "H") << endl;
}