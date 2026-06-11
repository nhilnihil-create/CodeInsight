/*https://atcoder.jp/contests/abc068/tasks/abc068_b*/
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
	int n, max_count = 0, val = 1;
	cin >> n;
	// cout << 2 / 2;
	for (int i = 1; i <= n; i++)
	{
		int count = 0, a = i;
		while (a % 2 == 0)
			a /= 2, count++;
		if (count > max_count)
			max_count = count, val = i;
	}
	cout << val;
}