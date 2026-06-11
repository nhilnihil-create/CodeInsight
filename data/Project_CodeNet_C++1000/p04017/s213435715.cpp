#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MN = 100200;
const int LOG = 19;
ll v[MN];
ll p[MN];
ll dp[LOG][MN];
int main() {
	ll n,l;
	scanf("%lld",&n);
	for(int i=0;i<n;i++) {
		scanf("%lld",&v[i]);
	}
	scanf("%lld",&l);
	for(int i=0;i<n-1;i++) {
		p[i] = upper_bound(v,v+n,v[i]+l)-v-1;
		dp[0][i] = p[i];
	}
	dp[0][n-1] = n-1;
	for(int i=1;i<LOG;i++) {
		for(int j=0;j<n;j++) {
			dp[i][j] = dp[i-1][dp[i-1][j]];
		}
	}
	ll q;
	scanf("%lld",&q);
	while(q--) {
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		if(a > b) {swap(a,b);}
		ll tot = 0;
		for(int i=LOG-1;i>=0;i--) {
			if(dp[i][a] < b) {
				a = dp[i][a];
				tot += 1<<i;
			}
		}
		tot++;
		printf("%lld\n",tot);
	}
}