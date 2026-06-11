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

int cnt(ll x) {
	int r = 0;
	while(x>=10) {
		r++;
		x/=10;
	}
	return r+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin >> n;
	ll ans = 1000000;
	for(ll i = 1; i*i<=n; i++){
		if (n%i==0) {
			ll d1 = i, d2 = n/i;
			int r = max(cnt(d1),cnt(d2));
			if (r < ans) {
				ans = r;
			}
		}
	}
	cout << ans << "\n";
	

}
