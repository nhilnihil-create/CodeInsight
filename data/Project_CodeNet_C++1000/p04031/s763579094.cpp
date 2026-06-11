#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define scout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	vint a(n);
	rep(i,n) cin >> a[i];
	ll ans = INF;
	for(int i=-100;i<=100;i++) {
		ll s=0;
		rep(j,n) {
			s+=(i-a[j])*(i-a[j]);
		}
		ans=min(ans,s);
	}
	cout << ans << endl;
}