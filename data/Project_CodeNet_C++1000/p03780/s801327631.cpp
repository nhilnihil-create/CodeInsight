#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 5005;

int dp1[N][N], dp2[N][N];
int a[N];

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dp1[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			dp1[i][j] = dp1[i - 1][j];
			if(j - a[i] >= 0 && dp1[i - 1][j - a[i]]) dp1[i][j] = 1;
		}
	}
	dp2[n + 1][0] = 1;
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j <= k; j++) {
			dp2[i][j] = dp2[i + 1][j];
			if(j - a[i] >= 0 && dp2[i + 1][j - a[i]]) dp2[i][j] = 1;
		}
	}
	for(int i = 1; i <= n + 1; i++) {
		for(int j = 1; j <= k; j++)
			dp2[i][j] += dp2[i][j - 1];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		// want [k - a[i], k)
		int l = k - a[i], r = k - 1;
		bool yes = false;
		for(int j = 0; j <= k; j++) {
			if(dp1[i - 1][j] == 0) continue;
			int wl = max(l - j, 0);
			int wr = r - j;
			if(wr < 0) continue;
			if(dp2[i+1][wr] - (wl ? dp2[i+1][wl-1] : 0)) yes = true;
		}
		if(!yes) cnt++;
	}
	cout << cnt << endl;
	
}



