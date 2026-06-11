/*https://atcoder.jp/contests/abc062/tasks/abc062_b*/
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
	int h, w;
	char a[200][200];
	cin >> h >> w;
	for (int i = 0; i < h + 2; i++)
	{
		for (int j = 0; j < w + 2; j++)
			a[i][j] = '#';
	}
	for (int i = 1; i < h + 1; i++)
	{
		for (int j = 1; j < w + 1; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < h + 2; i++)
	{
		for (int j = 0; j < w + 2; j++)
			cout << a[i][j];
		cout << endl;
	}

}