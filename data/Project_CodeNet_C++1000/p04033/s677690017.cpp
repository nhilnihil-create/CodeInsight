#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long a, b;
	cin >> a >> b;
	if (a * b <= 0)
		cout << "Zero" << endl;
	else if (a > 0)
		cout << "Positive" << endl;
	else if (b < 0)
	{
		if ((long long)(abs(a) - abs(b) + 1) % 2 == 0)
			cout << "Positive" << endl;
		else
			cout << "Negative" << endl;
	}
	return 0;
}
