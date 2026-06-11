/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Os")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
*/
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld; 

#define X first
#define Y second
#define MP make_pair

using namespace std;
    
const int N = 2e3 + 123;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

int n;
ll a[N], x, dp[N][N];
ll res;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> x;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		dp[0][i] = a[i];
		res += a[i];
	}

	for(int k = 1;k < n;k++){
		ll now = 0;
		for(int i = 1;i <= n;i++){
			int nxt = i - k;
			if(nxt <= 0)
				nxt += n;
			//cout << nxt << " " << i << "\n";
			dp[k][i] = min(dp[k - 1][i], a[nxt]);
			now += dp[k][i];
		}
		now += k * x;
		res = min(res, now);
	}

	cout << res;

	return 0;
}