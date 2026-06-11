#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n, ma, mb;
int a[N], b[N], c[N];
int dp[N][20*N][20*N];

int solve (int i, int aa, int bb)
{
	if (aa >0 && bb >0)
		if (abs((double)aa / (double)bb - (double(ma) / double(mb))) <= 1e-9) {
			return 0;
		}
	if (i >= n) {
		return 1e9;
	}
	int &res = dp[i][aa][bb];
	if (res != -1)
		return res;
	int solve1 = 0, solve2 = 0;
	solve1 = solve(i+1, a[i]+aa, b[i]+bb)+c[i];
	solve2 = solve(i+1, aa, bb);
	return res = min(solve1, solve2);
}

int main ()
{
	cin >> n >> ma >> mb;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i< n ; i ++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	
	int s = solve(0, 0, 0);
	if (s >= 1e9)
		cout << -1 << endl;
	else
		cout << s << endl;
	return 0;
}
