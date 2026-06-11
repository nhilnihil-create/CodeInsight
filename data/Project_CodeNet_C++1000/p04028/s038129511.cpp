#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 201010

ll MOD = 1e9+7;
ll N,K;
string S;
ll dp[5010][5010];

ll E(ll a, ll K){
	if (K==0)return 1;
	ll h = E(a,K/2);
	h=(h*h)%MOD;
	if(K%2)h=(h*a)%MOD;
	return h;
}

ll inv(ll x){
	return E(x, 1e9+5);
}

int main(){
	cin>>N>>S;
	K=SZ(S);
	dp[1][0] = 1;
	dp[1][1] = 2;
	for (int i=1;i<=N;++i){
		for (int j=0;j<=N;++j){
			// cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
			if (j == 0){
				dp[i+1][j] = (dp[i+1][j] + dp[i][j])%MOD;
				dp[i+1][j+1] = (2*dp[i][j] + dp[i+1][j+1])%MOD;
			}else{
				dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j])%MOD;
				dp[i+1][j+1] = (2*dp[i][j] + dp[i+1][j+1])%MOD;
			}
		}
	}
	cout<<dp[N][K]*inv(E(2,K))%MOD<<'\n';
}