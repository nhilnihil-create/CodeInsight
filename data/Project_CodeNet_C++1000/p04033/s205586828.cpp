/*https://atcoder.jp/contests/agc002/tasks/agc002_a*/
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
	long long a, b;
	cin >> a >> b;
	if (a > 0 && b < 0)
		swap(a, b);
	if (a < 0 && b < 0)
	{
		a = abs(a - b);
		if ((a + 1) % 2 == 0)
			cout << "Positive";
		else
			cout << "Negative";
	}
	else  if (a < 0 && b > 0)
		cout << "Zero";
	// else if (a == 0 || b == 0)
	// 	cout << "0";
	else
		cout << "Positive";
}