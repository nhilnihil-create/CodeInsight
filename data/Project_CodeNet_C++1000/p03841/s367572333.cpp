//2018年  3月 26日 月曜日 16:49:42 JST
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
typedef pair<pi, int> ppi;
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

int N;
ppi A[MAX_N]; //[0, A[i].fst.fst] に数A[i].secをA[i].fst.secだけマッチング。
ppi B[MAX_N]; //同様[B[i].fst.fst N * N]
int ans[510 * 510]; 

void solve() {
	cin >> N;
	memset(ans, -1, sizeof(ans));
	rep(i, 0, N) {
		int a; cin >> a; a--;
		A[i] = make_pair(pi(a - 1, i), i);
		B[i] = make_pair(pi(-(a + 1), N - i - 1), i);
		ans[a] = i;
	}
	sort(A, A + N);
	sort(B, B + N);
	rep(i, 0, N) {
		int l = A[i].fst.fst, c = A[i].fst.sec, num = A[i].sec;
		// debug(l, c, num, vi(ans, ans + N * N));
		if(c == 0) continue;
		int at = 0;
		while(at <= l && c != 0) {
			if(ans[at] == -1) {
				ans[at] = num;
				c--;
			}
			at++;
		}
		if(at == l + 1 && c != 0) {
			cout << "No\n"; return;
		}
	}
	rep(i, 0, N) {
		int r = B[i].fst.fst * -1, c = B[i].fst.sec, num = B[i].sec;
		if(c == 0) continue;
		// debug(r, c, num, vi(ans, ans + N * N));
		int at = N * N - 1;
		while(at >= r && c != 0) {
			if(ans[at] == -1) {
				ans[at] = num;
				c--;
			}
			at--;
		}
		if(at == r - 1 && c != 0) {
			cout << "No\n"; return;
		}
	}
	cout << "Yes\n";
	rep(i, 0, N * N) cout << ans[i] + 1 << " ";
	cout << "\n";
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

