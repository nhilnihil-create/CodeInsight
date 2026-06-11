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

struct Fenwick {
	vl t;
	Fenwick(int n) : t(n+1) {}
	ll sum(int pos) {
		++pos;
		ll ret = 0;
		while(pos > 0) {
			ret += t[pos];
			pos &= (pos-1);
		}
		return ret;
	}
	void add(int pos, ll val) {
		++pos;
		while(pos < t.size()) {
			t[pos] += val;
			pos += (pos & -pos);
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int n;
	ll k;
	cin >> n >> k;
	vl a(n+1);
	rep(i,1,n+1) {
		cin >> a[i];
		a[i] -= k;
	}
	rep(i,1,n+1) {
		a[i] += a[i-1];
	}
	map<ll, ll> r;
	rep(i,0,n+1) {
		if(r.find(a[i]) != r.end()) {
			r[a[i]]++;
		} else {
			r[a[i]] = 1;
		}
	}
	map<ll, int> idx;
	Fenwick tree(r.size());
	int t = 0;
	for(auto e : r) {
		idx[e.F] = t++;
		tree.add(idx[e.F], e.S);
	}
	ll ret = 0;
	ll mx = r.rbegin()->F;
	rep(i,0,n+1) {
		tree.add(idx[a[i]], -1);
		ret += tree.sum(idx[mx]) - tree.sum(idx[a[i]]-1);
	}
	cout << ret << '\n';
	return 0;
}