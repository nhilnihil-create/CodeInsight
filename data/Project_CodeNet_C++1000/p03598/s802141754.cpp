#include<bits/stdc++.h>
#define int long long
#define fo(i,n)   for(i=0;i<n;i++)
#define mod       1000000007
using namespace std;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("codefi.txt", "r", stdin);
	freopen("codefo.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int k;
	cin >> k;
	int a[n];
	int i;
	fo(i, n)
	cin >> a[i];

	int diff1 = 0, diff2 = 0;
	int sum = 0;
	fo(i, n)
	{
		diff1 = abs(a[i] - k);
		diff2 = abs(0 - a[i]);
		if (diff1 < diff2)
			sum += 2 * diff1;
		else
			sum += 2 * diff2;
	}
	cout << sum << endl;
}