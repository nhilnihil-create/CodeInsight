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

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int N;
ll A[MAX_N];

bool sub_solve() {
	if(N == 1) return (A[0] - 1) % 2;
	bool second = false;
	while(true) {
		// debug(vi(A, A + N));
		int odd = 0;
		bool one = false;
		rep(i, 0, N) {
			if(A[i] % 2) odd++;
			if(A[i] == 1) one = true;
		}
		if((N - odd) % 2) return (second ^ 1);
		else if(odd != 1 || one) return second;
		else {
			if(A[0] % 2) A[0]--;
			ll g = A[0];
			rep(i, 0, N) {
				if(A[i] % 2) A[i]--;
				g = gcd(g, A[i]);
			}
			rep(i, 0, N) A[i] /= g;
		}
		second ^= 1;
	}
}

void solve() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	if(sub_solve()) {
		cout << "First\n";
	}
	else cout << "Second\n";
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

