#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = 5042 + 17;
const int mod = (int)1e9 + 7;

int n, l;
string s;

void read()
{
	cin >> n >> s;
	l = s.size();
}

int dp[MAXN][MAXN];

int pw(int x, int p)
{
	int ret = 1;
	while(p)
	{
		if(p & 1) ret = (ret * 1ll * x) % mod;
		x = (x * 1ll * x) % mod;
		p >>= 1;
	}

	return ret;
}

void solve()
{
	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int c = 0; c < n; c++)
			if(dp[i][c])
			{
				dp[i + 1][max(c - 1, 0)] = (dp[i + 1][max(c - 1, 0)] + dp[i][c]) % mod;
				dp[i + 1][c + 1] = (dp[i + 1][c + 1] + 2ll * dp[i][c]) % mod;
			}

	int answer = (dp[n][l] * 1ll * pw(pw(2, l), mod - 2)) % mod;	
	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}

