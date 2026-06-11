#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int	x, a;
	cin >> x >> a;
	cout << (x - a < 0 ? 0 : x - a) << endl;
}