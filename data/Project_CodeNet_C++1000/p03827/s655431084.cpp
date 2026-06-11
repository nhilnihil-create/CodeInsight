/*https://atcoder.jp/contests/abc052/tasks/abc052_b*/
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
	int n, count = 0, max_count = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'I')
			count++;
		else if (s[i] == 'D')
			count--;
		max_count = max(max_count, count);
	}
	cout << max_count;
}