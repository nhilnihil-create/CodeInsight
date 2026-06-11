#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100500;
const int MOD = 1e9 + 7;

int mul(int a, int b)
{
	return (long long) a * b % MOD;
}

int arr[MAXN];
int fac[MAXN];
int n;

int main()
{
	fac[0] = 1;
	for (int i = 0; i < MAXN - 1; i++)
		fac[i + 1] = mul(fac[i], i + 1);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		arr[i] = min(arr[i], 2 * i + 1);
	ll cnt = 0;
	ll res = 1;
	for (int i = 0; i < n; i++)
	{		
		if (arr[i] < 2 * cnt + 1)
			res = mul(res, cnt + 1);
		else
			cnt++;
	}
	
	res = mul(res, fac[cnt]);
	cout << res << '\n';

	return 0;
}
