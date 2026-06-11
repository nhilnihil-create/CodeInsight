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
	vi a(n);
	ll total = 0;
	rep(i,0,n) {
		cin >> a[i];
		total += (ll)a[i];
	}
	map<int, int> r;
	rep(i,0,n) {
		if(r.find(a[i]) != r.end()) {
			r[a[i]]++;
		} else {
			r[a[i]] = 1;
		}
	}
	rep(i,1,n) {
		a[i] = max(a[i-1],a[i]);
	}
	vi idx;
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
		int j = idx[i];
		int x = a[j-1];
		int y = a[j];
		auto start = r.lower_bound(x);
		auto end = r.lower_bound(y);
		ll ret = 0;
		for (auto it = start; ; ++it) {
			int diff = (it->F) - x;
			if(diff == 0) continue;
			int cnt = it->S;
			ret += ((ll)diff * cnt);
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
