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

int N; ll L, T;
ll A[MAX_N], W[MAX_N];
ll ans[MAX_N];

void solve() {
	cin >> N >> L >> T;
	rep(i, 0, N) {
		cin >> A[i] >> W[i]; W[i]--;
	}
	ll cnt = 0;
	rep(i, 1, N) {
		if(W[i] != W[0]) {
			ll b; 
			if(W[0] == 0) b = A[i] - A[0];
			else b = L - (A[i] - A[0]);
			if(2 * T < b) continue;
			if(2 * T == b) cnt++;
			else {
				cnt += 1 + (2 * T - b) / L;
			}
		}
	}
	rep(i, 0, N) {
		ans[i] = W[i] == 0 ? (T + A[i]) % L : (L - (T - A[i] + L) % L) % L;
	}
	cnt %= N;
	if(W[0] == 1) cnt = (N - cnt) % N;
	ll at = ans[0];
	sort(ans, ans + N);
	ll id;
	ll b = lower_bound(ans, ans + N, at) - ans;
	if(upper_bound(ans, ans + N, at) - lower_bound(ans, ans + N, at) == 1) {
		id = b;
	}
	else {
		if(W[0] == 0) id = b + 1;
		else id = b;
	}
	// debug(vi(ans, ans + N), id, cnt);
	rep(i, 0, N) {
		cout << ans[(i + id - cnt + N) % N] << "\n";
		// else cout << ans[(-i + id - cnt + 2 * N) % N] << "\n";
	}
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
	srand((unsigned int)time(NULL));
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

