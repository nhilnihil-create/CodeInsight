//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}



//head



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vi x(n);
	rep(i, n) cin >> x[i];
	int m;
	ll k;
	cin >> m >> k;
	vi a(m);
	rep(i, m) {
		cin >> a[i];
		a[i] -= 2;
	}

	int lo = log2(double(k))+1.01;
	vvi vec(lo, vi(n-1));
	rep(i, n-1) {
		vec[0][i] = i;
	}
	rep(i, m) {
		swap(vec[0][a[i]], vec[0][a[i]+1]);
	}
	rep(i, lo-1) {
		rep(j, n-1) {
			vec[i+1][j] = vec[i][vec[i][j]];
		}
	}

	vi vv(n-1), vj(n-1);
	rep(i, n-1) vv[i] = i;
	vi::iterator now, pre;
	now = vj.begin();
	pre = vv.begin();
	rep(i, lo) if(k>>i&1) {
		rep(j, n-1) {
			*(now+j) = vec[i][*(pre+j)];
		}
		swap(now, pre);
	}

	vector<ll> len(n-1);
	rep(i, n-1) len[i] = ll(x[i+1])-x[i];

	ll nn = x[0];
	cout << x[0] << '\n';
	rep(i, n-1) {
		nn += len[*(pre+i)] ;
		cout << nn << '\n';
	}
}