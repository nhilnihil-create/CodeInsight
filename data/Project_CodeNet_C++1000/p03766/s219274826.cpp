#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 2000110
ll MOD = 1e9+7;

ll ans[MAXN];
ll pref[MAXN];
ll N,T;

ll sum(ll a, ll b){
	return (MOD + pref[b] - pref[a-1])%MOD;
}

int main(){
	cin>>N;
	for (int i=1;i<=N;++i){
		ans[i] = 1;
		pref[i] = pref[i-1]+1;
	}
	ans[N+1] = T = N;
	pref[N+1] = pref[N] + ans[N+1];

	for (int i=N+2;i<=2*N;++i){
		ans[i] = (N-1)*(N-1)%MOD;
		ans[i] += (sum(i-N-1,i-1) + MOD - ans[i-2])%MOD;
		ans[i] %= MOD;
		pref[i] = (pref[i-1] + ans[i]) %MOD;
	}
	cout<<ans[N*2];
}