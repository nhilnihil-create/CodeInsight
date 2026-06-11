#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a, b, c;

	cin >> a >> b >> c;

	cout << (((a <= c) && (c <= b)) ? "Yes" : "No") << endl;
}
