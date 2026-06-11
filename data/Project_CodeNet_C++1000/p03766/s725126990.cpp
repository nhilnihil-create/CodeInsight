#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 1000000 + 10000;
const int MOD = 1000000000 + 7;

int n;
int f[MAXN], s[MAXN];

void add(int &x, long long y)
{
	x = (x + y) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;

	f[1] = n, s[1] = f[1];

	for(int i = 2; i <= n; i++)
	{
		f[i] = (f[i] + f[i - 1]) % MOD;
		f[i] = (f[i] + (i >= 4 ? s[i - 3] : 0)) % MOD;
		f[i] = (f[i] + (long long)(n - 1) * (n - 1)) % MOD;
		f[i] = (f[i] + (i >= 4 ? n - i + 2 : n - 1)) % MOD;

		s[i] = (s[i - 1] + f[i]) % MOD;
	}

	int ans = f[n];
	cout << ans << endl;
	
	return 0;
}
