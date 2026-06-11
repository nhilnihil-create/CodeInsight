#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<functional>
#include<set>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
typedef pair<int, int>P;
int a[5005];
int dp[5005][5005];
void init() {
	REP(i, 5005)
		REP(j, 5005)dp[i][j] = 0;
}
signed main() {
	int n, k; cin >> n >> k;
	REP(i, n)cin >> a[i]; sort(a, a + n);

	int ok = -1, ng = n;
	while(ng-ok>1){
	int i = (ok + ng) / 2;
		init();
		dp[0][0] = 1;
		for (int j = 0; j < n; j++) {//card
			for (int l = 0; l < k; l++) {
				dp[j + 1][l] += dp[j][l];
				if (j != i&&l + a[j] <= k)dp[j + 1][l + a[j]] += dp[j][l];
			}
		}
		int flg = 0;
		for (int j = max(0ll,k - a[i]); j <= k - 1; j++) {
			if (dp[n][j])flg++;
		}
		if (flg)ng = i;
		else ok = i;
	}
	cout << ng << endl;
}
