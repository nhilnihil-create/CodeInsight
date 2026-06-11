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
	int n, m;
	cin >> n >> m;
	vi x(n);
	rep(i,0,n) {
		cin >> x[i];
	}
	map<int, int> r;
	rep(i,0,n) {
		r[x[i]]++;
	}
	vector<vi> b(m);
	for(auto e:r) {
		int idx = e.F % m;
		b[idx].pb(e.S);
	}
	int ret = 0;
	for(int k=0; k<=m/2; ++k) {
		int total = 0;
		rep(i,0,sz(b[k])) {
			total += b[k][i];
		}
		if((2*k)%m == 0) {
			ret += total/2;
			continue;
		}
		int rtotal = 0;
		rep(i,0,sz(b[m-k])) {
			rtotal += b[m-k][i];
		}
		int idx;
		int limit = abs(total - rtotal)/2;
		if(total == rtotal) {
			ret += total;
			idx = -1;
		} else if(total > rtotal) {
			ret += rtotal;
			idx = k;
		} else {
			ret += total;
			idx = m-k;
		}
		if(idx == -1) continue;
		total = 0;
		rep(i,0,sz(b[idx])) {
			total += b[idx][i]/2;
		}
		ret += min(limit, total);
	}
	cout << ret << '\n';
	return 0;
}
