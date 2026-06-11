#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio() ios_base::sync_with_stdio(false);
#define rmod(x, y) ((((x)%(y))+(y))%(y))
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T, typename R = null_type, typename C = less<T>>
tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update> ordered_set(){
	return tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update>();
}

const int maxn = 45, maxs = 405;
int n, ma, mb, a[maxn], b[maxn], c[maxn];
int dp[maxn][maxs][maxs];

int main(){
	scanf("%d %d %d", &n, &ma, &mb);
	for(int i = 1; i<=n; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);

	memset(dp, 63, sizeof(dp));
	int ans = dp[0][0][0];
	dp[0][0][0] = 0;
	for(int i = 1; i<=n; i++){
		for(int s = 0; s<maxs; s++){
			for(int k = 0; k<maxs; k++){
				dp[i][s][k] = dp[i-1][s][k];
				if (s>=a[i] && k>=b[i])
					dp[i][s][k] = min(dp[i][s][k], dp[i-1][s-a[i]][k-b[i]]+c[i]);
			}
		}
	}
	for(int mul = 1; ma*mul<=400 && mb*mul<=400; mul++) ans = min(ans, dp[n][ma*mul][mb*mul]);
	if (ans == dp[0][404][404]) puts("-1");
	else printf("%d\n", ans);
	return 0;
}
