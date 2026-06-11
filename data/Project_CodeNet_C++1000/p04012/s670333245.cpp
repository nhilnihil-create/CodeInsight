/*https://atcoder.jp/contests/abc044/tasks/abc044_b*/
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
	string w;
	cin >> w;
	for (int i = 0; i < w.size(); i++)
	{
		int count = 0;
		for (int j = 0; j <w.size(); j++)
		{
			if (w[i] == w[j])
				count++;
		}
		if (count % 2 != 0)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}