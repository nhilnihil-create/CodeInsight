#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int mp[111111];
int mo[111111];

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	ll n, m;cin >> n >> m;
	ll ans = 0;
	
	REP(i,n){
		int a;
		cin >> a;
		mp[a]++;
		mo[a%m]++;
	}
	
	REP(i, m){
		if(i == 0 || i == m - i){
			ans += mo[i] / 2;
			mo[i] %= 2;
			continue;
		}
		int pa = m - i;
		int tmp = min(mo[i], mo[pa]);
		ans += tmp;
		mo[i] -= tmp;
		mo[pa] -= tmp;
	}
	
	REP(i, 111111){
		while(mp[i] > 1 && mo[i%m] > 1){
			ans++;
			mp[i] -= 2;
			mo[i%m] -= 2;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
