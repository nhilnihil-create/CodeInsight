#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long INF = 1e18;
int n, f[maxn];
long long ini[maxn], dp[maxn][3];

inline void putit(){
	scanf("%d", &n); char opt[30];
	scanf("%lld", &ini[1]); f[1] = 1;
	for(int i = 2; i <= n; ++i){
		scanf("%s", opt + 1); f[i] = (opt[1] == '+') ? 1 : -1;
		scanf("%lld", &ini[i]);
	} 
}

inline void check(){
	for(int i = 1; i <= n; ++i){
		printf("dp[%d][0] = %lld ", i, dp[i][0]);
		printf("dp[%d][1] = %lld ", i, dp[i][1]);
		printf("dp[%d][2] = %lld ", i, dp[i][2]);
		printf("\n");
	}
}

inline void workk(){
	long long lin0, lin1, lin2;
	dp[1][0] = ini[1]; dp[1][1] = dp[1][2] = -INF;
	for(int i = 2; i <= n; ++i){
		if(f[i] == 1){
			lin0 = dp[i - 1][0] + ini[i];
			lin1 = dp[i - 1][1] - ini[i];
			lin2 = dp[i - 1][2] + ini[i];
			dp[i][0] = max(lin0, lin1); dp[i][1] = max(lin1, lin2); dp[i][2] = lin2;
		}
		else{
			lin0 = dp[i - 1][0] - ini[i];
			lin1 = dp[i - 1][1] + ini[i];
			lin2 = dp[i - 1][2] - ini[i];
			dp[i][1] = max(lin1, lin0); dp[i][2] = max(lin2, lin1);
			dp[i][0] = max(lin0, lin1); dp[i][1] = max(dp[i][1], dp[i][2]);
		}
	}
	//check();
	cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}

int main()
{
	//freopen("lpl.in", "r", stdin);
	//freopen("lpl.out", "w", stdout);
	putit();
	workk();
	return 0;
}