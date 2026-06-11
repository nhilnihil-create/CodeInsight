#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int a, b;
	cin >> a >> b;
	if (a + b < 24)
		cout << a + b << endl;
	else
		cout << a + b - 24 << endl;
	return 0;
}
