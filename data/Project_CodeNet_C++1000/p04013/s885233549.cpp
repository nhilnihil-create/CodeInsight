#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio() ios_base::sync_with_stdio(false)
#define rmod(x, y) ((((x)%(y))+(y))%(y))
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T, typename R = null_type, typename C = less<T>>
tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update> ordered_set(){
    return tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update>();
}

const int maxn = 53, maxs = 50*50 +5;
int n, tar, a[maxn];
ll dp[maxn][maxs][maxn];

int main(){
	scanf("%d %d", &n, &tar);
	for(int i = 1; i<= n; i++) scanf("%d", &a[i]);
	dp[0][0][0] = 1;
	for(int i = 1; i<=n; i++){
		for(int s = 0; s<maxs; s++){
			for(int c = 0; c<=i; c++){
				dp[i][s][c] = dp[i-1][s][c];
				if (c>0 && s>=a[i]) dp[i][s][c] += dp[i-1][s-a[i]][c-1];
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i<=n; i++){
		ans+= dp[n][i*tar][i];
	}
	printf("%lld\n", ans);

    return 0;
}
