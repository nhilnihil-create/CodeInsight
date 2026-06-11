/*https://atcoder.jp/contests/abc074/tasks/abc074_b*/
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
	int n, k, x[100];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	int dist = 0;
	for (int i = 0; i < n; i++)
	{
		dist += min(2 * abs(k - x[i]), 2 * x[i]);
	}
	cout << dist;

}