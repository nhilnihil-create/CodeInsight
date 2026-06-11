#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(obj) obj.begin(), obj.end()
#define dbg(x) cerr << #x << ":" << x << " "
#define dbgl(x) cerr << #x << ":" << x << "\n"
#define dbgv(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define dbgvv(vv) cerr << #vv << ":\n"; for (auto vec : vv) { for (auto e : vec) cerr << e << " "; cerr << endl; }
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int cc(vi a) {
	int res = 0, max_h = 0;
	for (int ai : a) {
		if (max_h < ai) {
			res++;
			max_h = ai;
		}		
	}
	return res;
}

int main () {
	int N, K; cin >> N >> K;
	vi a(N); rep(i, N) cin >> a.at(i);
	ll ans = 1000000000LL * 15;
	rep(k, 1 << N) {		
		int x = k; vi b = a;
		ll temp = 0;
		int max_h = 0;
		rep(t, N) {			
			if (x & 1) {				
				if (max_h >= b.at(t)) {
					temp += max_h + 1 - b.at(t);
					b.at(t) = max_h + 1;
					max_h++;
				} else max_h = b.at(t);
			}
			x >>= 1;
		}
		if (cc(b) >= K) ans = min(ans, temp);
	}				
	cout << ans << endl;
}