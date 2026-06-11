#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 200010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

struct BIT { //0-origin!!! update and get just like lazy_segtree
	int n; vl bit0, bit1;
	void init(int mx) {
		n = mx;
		bit0 = vl(n + 1, 0); bit1 = vl(n + 1, 0);
	}
	BIT(int mx = 0) { init(mx); } 

	ll ga(vl& bit, int i) {
		ll s = 0;
		while(i > 0) { s += bit[i]; i -= i & -i; }
		return s;
	}
	void app(vl& bit, int i, ll x) {
		while(i <= n) { bit[i] += x; i += i & -i; }
	}
	void update(int a, int b, ll x) { //[a, b)
		a++;
		app(bit0, a, -x * (a - 1));
		app(bit1, a, x);
		app(bit0, b + 1, x * b);
		app(bit1, b + 1, -x);
	}
	ll get(int a, int b) { //[a, b)
		a++;
		return (ga(bit1, b) * b + ga(bit0, b)) 
			- (ga(bit1, a - 1) * (a - 1) + ga(bit0, a - 1));
	}
	void show() {
		vi res;
		rep(i, 0, n) res.pb(get(i, i + 1));
		debug(res);
	}
};

int N, M;
vi point[MAX_N];
vector<pi> interval[MAX_N];
int ans[MAX_N];
BIT bit;

void solve() {
	cin >> N >> M;
	bit.init(M + 2);
	rep(i, 0, N) {
		int l, r; cin >> l >> r; r++;
		point[l].pb(r);
	}
	rep(i, 1, M + 1) {
		for(int j = -i; j + i <= M; j += i) {
			int l = j, r = j + i;
			if(l >= 0) interval[l + 1].pb(pi(r + 1, -i));
			interval[r + 1].pb(pi(r + 1, i));
		}
	}
	rep(i, 0, M + 2) {
		rep(j, 0, sz(interval[i])) {
			pi p = interval[i][j];
			int v = abs(p.sec);
			if(p.sec < 0) {
				ans[v] -= bit.get(p.fst, M + 2);
			}
			else ans[v] += bit.get(p.fst, M + 2);
		}
		rep(j, 0, sz(point[i])) {
			int p = point[i][j];
			bit.update(p, p + 1, 1);
		}
	}
	rep(i, 1, M + 1) {
		cout << ans[i] << "\n";
	}
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
#ifdef LOCAL
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

