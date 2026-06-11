#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin() , v.end()
#define inputv(v,n) rep(i,n){\
    ll x;\
    cin>>x;\
    v.push_back(x);\
    }
const ll INF = 99999999999999;
const ll MOD = 1000000007;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, ans = 0, w, l;
vl A;
class LCA {
public:
	ll LOG_N = floor(log2(n)) + 1;
	vector<vl> NEXT;
	vl DEPTH;


	void init() {
		DEPTH = vl(n, -1);
		// NEXT[0]を計算
		NEXT = vector<vl>(LOG_N + 2, vector<ll>(n));
		for (ll i = 0; i < n; ++i) {
			NEXT[0][i] = upper_bound(all(A), A[i] + l) - A.begin() - 1;
		}

		// NEXTを計算
		for (ll k = 0; k < LOG_N; k++) {
			for (ll i = 0; i < n; i++) {
				if (NEXT[k][i] == n) {
					NEXT[k + 1][i] = n;
				}
				else {
					NEXT[k + 1][i] = NEXT[k][NEXT[k][i]];
				}
			}
		}
	}

	ll vertex(ll p, ll Q) {
		for (ll k = LOG_N - 1; k >= 0; --k) {
			if (p == -1) {
				break;
			}
			if ((Q >> k) & 1) {
				p = NEXT[k][p];
			}
		}

		return p;
	}

	ll depth(ll x) {
		if (DEPTH[x] == -1) {
			ll ok = n, ng = -1;
			while (ok - ng > 1) {
				if (this->vertex(x, (ok + ng) / 2) > -1)ng = (ok + ng) / 2;
				else ok = (ok + ng) / 2;
			}
			DEPTH[x] = ok;
			return ok;
		}
		else return DEPTH[x];
	}

	ll kyoutuu(ll x, ll y) {
		ll a = this->depth(x);
		ll b = this->depth(y);
		if (a > b) {
			swap(x, y);
			swap(a, b);
		}
		ll t = this->vertex(y, b - a);

		ll ok = n, ng = -1;
		while (ok - ng > 1) {
			ll mid = (ok + ng) / 2;
			if (this->vertex(x, mid) == this->vertex(t, mid))ok = (ok + ng) / 2;
			else ng = (ok + ng) / 2;
		}

		/*祖先を出力したい場合はreturn this->vertex(x, ok);*/
		return b - a + ok * 2 + 1;
	}

	ll saitei(ll x, ll y) {
		if (x > y)swap(x, y);
		ll ok = n, ng = -1;
		while (ok - ng > 1) {
			ll mid = (ok + ng) / 2;
			if (this->vertex(x, mid) >= y)ok = (ok + ng) / 2;
			else ng = (ok + ng) / 2;
		}

		return ok;
	}

};

void input() {
	cin >> n;
	inputv(A, n);
	A.push_back(INF);
	n++;
	cin >> l;
	cin >> q;

	LCA LCA1;
	LCA1.init();
	while (q--) {
		cin >> x >> y;
		cout << LCA1.saitei(x-1, y-1) << endl;
	}
}


void solve() {
}

int main() {
	input();
	solve();
}