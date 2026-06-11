/*https://atcoder.jp/contests/agc014/tasks/agc014_a*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	long long a, b, c, d, e, f, count = 0;
	cin >> a >> b >> c;
	int flag = 0;
	if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0 )
	{
		cout << count;
		return 0;
	}
	if (a == b && a == c)
	{
		cout << "-1";
		return 0;
	}
	do {
		count++;
		d = b / 2 + c / 2;
		e = a / 2 + c / 2;
		f = a / 2 + b / 2;
		a = d, b = e, c = f;
		if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0 )
			flag = 1;
		// cout << a << " " << b << " " << c << "->" << flag << endl;

	} while (flag == 0);
	cout << count;
}