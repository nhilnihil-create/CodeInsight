#include <bits/stdc++.h>
#define ADD(a, b) a = (a + (ll)b) % mod
#define MUL(a, b) a = (a * (ll)b) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define rer(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef vector<ll> vi;
typedef complex<double> comp;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest) { 
	cout << arg << " "; Debug(rest...); }
template<class T>ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<< ", ";out<<v.back();}out << "]";return out;}
template<class S, class T>ostream& operator<< (ostream& out, const pair<S, T>& v) {
	out << "(" << v.first << ", " << v.second << ")";return out;}
const int MAX_N = 200010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

ll N = 1;


bool all_nine(ll v) {
	while(v) {
		if(v % 10 != 9) return false;
		v /= 10;
	}
	return true;
}


string ll_to_str(ll N) {
	string str;
	while(N) {
		str += (N % 10 + '0');
		N /= 10;
	}
	reverse(all(str));
	return str;
}

char get_ans(ll res) {
	string sn = ll_to_str(N);
	string sres = ll_to_str(res);
	bool s;
	if(N <= res && sn <= sres) s = true;
	else if(N > res && sn > sres) s = true;
	else s = false;
	return s ? 'Y' : 'N';
}

bool ok(ll res) {
	//char c = get_ans(res);
	cout << "? " << res << endl;
	char c; cin >> c;
	return c == 'Y';
}


void solve() {
	ll res = 0;
	for(ll i = 0; i < 10; i++) {
		ll lv, rv = 10;
		if(i == 0) lv = 1;
		else lv = 0;
		while(rv - lv > 1) {
			ll m = (lv + rv) / 2;
			if(ok(res * 10 + m)) lv = m;
			else rv = m;
		}
		res = res * 10 + lv;
		//char c = get_ans(res + 1);
		cout << "? " << res + 1 << endl;
		char c; cin >> c;

		if((all_nine(res) && c == 'N') || (!all_nine(res) && c == 'Y')) {
			res -= 9;
			if(i == 0) lv = 0;
			else lv = -1;
			rv = 9;
			while(rv - lv > 1) {
				ll m = (lv + rv) / 2;
				if(ok(res * 10 + m * 10)) rv = m;
				else lv = m;
			}
			cout << "! " << res + rv << endl;
			return;
		}
	}
	cout << "!  1" << endl;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(5);
	/*
#ifdef LOCAL
    freopen("in.txt", "rt", stdin);
#endif	
*/
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}




