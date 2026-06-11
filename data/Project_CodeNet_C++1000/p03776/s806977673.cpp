#include <bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))

const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

int n,a,b;
pair<ll,ll> sol;

ll dp[300][300];

ll C(int n, int k) {
	if (n < k) return 0;
	if (n == k || k == 0) return 1;
	ll &ret = dp[n][k];
	if (ret) {
		return ret;
	}
	return ret = C(n-1,k-1) + C(n-1,k);
}

ll num[55];

ll eq(pair<ll,ll> a, pair<ll,ll> b) {
	return a.S * b.F == a.F * b.S;
}

ll gaus(ll x) {
	return x*(x+1)/2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cout << fixed << setprecision(8);
	
	cin >> n >> a >> b;
	
	map<ll,int> cnt;
	
	FOR(i,0,n){
		cin >> num[i];
		cnt[num[i]]++;
	}
	
	sort(num,num+n,greater<ll>());
	
	for (int i = 0; i < a; i++){
		sol.F+=num[i];
	}
	sol.S = a;
	
	ll ans = 0;
	for (int i = a; i <= b; i++){
		ll s = 0;
		for (int j = 0; j < i; j++) {
			s+=num[j];
		}		
		pair<ll,ll> frac = {s,i};
		if (! eq(sol,frac)) {
			break;
		}
		ll last = num[i-1];
		ll p = 0;
		for (int j = 0; j < i; j++) {
			p+=(num[j]==last);
		}
		ans+=C(cnt[last],p);
	}
	
	cout << (((double)sol.F)/sol.S) << "\n" << ans << "\n";
	
}
