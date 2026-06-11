#include<bits/stdc++.h>
#define int long long
#define fo(i,n)   for(i=0;i<n;i++)
#define mod       1000000007
using namespace std;

int chk(int n)
{
	int max = 0, cnt = 0;
	if (n % 2 == 0)
	{
		while (n / 2 != 0)
		{
			cnt++;
			n = n / 2;
		}
	}
	return cnt;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("codefi.txt", "r", stdin);
	freopen("codefo.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	int max = 0;
	int fin = 1;
	for (int i = 1; i <= n; i++)
	{
		int res = chk(i);
		if (res > max) {
			fin = i;
			max = res;
		}
	}

	cout << fin << endl;
}