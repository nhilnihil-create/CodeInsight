#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vl a(n);
	ll total = 0;
	rep(i,0,n) {
		cin >> a[i];
		total += a[i];
	}
	map<ll, ll> r;
	rep(i,0,n) {
		r[a[i]]++;
	}
	rep(i,1,n) {
		a[i] = max(a[i-1],a[i]);
	}
	vl idx;
	idx.pb(0);
	rep(i,1,n) {
		if(a[i] != a[i-1]) {
			idx.pb(i);
		}
	}
	int m = idx.size();
	vl ans(n);
	ll subtotal = 0;
	per(i,1,m) {
		ll j = idx[i];
		ll x = a[j-1];
		ll y = a[j];
		auto start = r.upper_bound(x);
		auto end = r.lower_bound(y);
		ll ret = 0;
		for (auto it = start; ; ++it) {
			ll diff = (it->F) - x;
			ll cnt = (it->S);
			ret += (diff * cnt);
			r[x] += cnt;
			it->S = 0;
			if(it == end) {
				break;
			}
		}
		ans[j] = ret;
		subtotal += ret;
	}
	ans[0] = total - subtotal;
	rep(i,0,n) {
		cout << ans[i] << '\n';
	}
	return 0;
}
