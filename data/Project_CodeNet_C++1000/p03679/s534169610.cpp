#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	int x, a, b;
	cin >> x >> a >> b;
	a *= -1;
	if (a + b <= 0)
		cout << "delicious" << endl;
	else if (a + b <= x)
		cout << "safe" << endl;
	else
		cout << "dangerous" << endl;
	return 0;
}
