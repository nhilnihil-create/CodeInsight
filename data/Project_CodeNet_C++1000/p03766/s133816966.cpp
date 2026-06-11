#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9+7;

int n;
int f[1000001];

int sub(int a,int b)
{
	int c = ((a - b)%mod + mod)%mod;
	return c;
}

int add(int a,int b)
{
	int c = (a + b)%mod;
	return c;
}

int mul(int a,int b)
{
	int c = (a * b)%mod;
	return c;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	f[0] = 1, f[1] = n; 
	int sum = f[0] + f[1];
	for (int i=2;i<=n;i++)
	{
		f[i] = add(add(mul(n-1,n-1), sub(sum,f[i-2])), (n - i + 1));
		sum = add(sum,f[i]);
	}	
	cout << f[n];
}