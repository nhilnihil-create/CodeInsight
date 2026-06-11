#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const int MN = 100100;
//MAX MIN
ll dp[MN][2];
vl v,w;
int main() {
	memset(dp,0,sizeof(dp));
	ll n;
	scanf("%lld",&n);
	ll rn;
	scanf("%lld",&rn);
	for(int i=0;i<n-1;i++) {
		char op;
		ll val;
		scanf(" %c %lld",&op,&val);
		if(op == '-') {
			w.push_back(rn);
			rn = 0;
			v.push_back(val);
		} else {
			rn += val;
		}
	}
	w.push_back(rn);
	for(int i=v.size()-1;i>=0;i--) {
		ll po = w[i+1]-v[i];
		ll pa = -w[i+1]-v[i];
		dp[i][0] = max(po+dp[i+1][0],pa-dp[i+1][1]);
		dp[i][1] = min(pa+dp[i+1][1],pa-dp[i+1][0]);
	}
	printf("%lld\n",w[0]+dp[0][0]);
}