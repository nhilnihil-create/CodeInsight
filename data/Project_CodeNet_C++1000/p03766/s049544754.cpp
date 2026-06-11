#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod 1000000007
ll dp[1000005],ret;
int main(){
	int n; cin >> n;
	for(int i=0;i<=n;i++) dp[i] = 1LL;
	ll add = 0LL,sum = 0LL;
	for(int i=3;i<=n;i++){
		add+=sum;
		add+=dp[i-3];
		add%=mod;
		sum+=dp[i-3];
		sum%=mod;
		dp[i]=(dp[i]+add)%mod;
	}
	ret = dp[n]+dp[n-1]*1LL*(n-1)%mod;
	for(int i=0;i<n-1;i++){
		ret += dp[i]*1LL*(n-1)%mod*(n-1)%mod;
		ret += dp[i]*1LL*(i+1)%mod;
	}
	cout << ret%mod << endl;
}