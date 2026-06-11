#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	int w, a, b;
	cin >> w >> a >> b;
	if (a <= b && b <= a + w)
		cout << 0 << endl;
	else
	{
		if (b - (a + w) >= 0)
			cout << b - (a + w) << endl;
		else
			cout << a - (b + w) << endl;
	}
	return 0;
}
