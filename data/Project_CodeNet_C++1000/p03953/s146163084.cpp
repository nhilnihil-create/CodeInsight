#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;
const double EPS = 1e-9;

#define ndl cout << '\n'
#define sz(v) int(v.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define present(a, x) (a.find(x) != a.end())
#ifdef LOCAL
#define db(...) ({cout << "> Line " << __LINE__  \
		<< ": "; _db(#__VA_ARGS__, __VA_ARGS__);})
#define RNG() rng()
#else
#define db(...) true
#define RNG() true
#endif

template<class T>
void _db(const char *dbStr, T e) {
	cout << dbStr << " = " << e << endl;
}
template<class T, class... L>
void _db(const char *dbStr, T e, L... r) {
  while(*dbStr != ',') cout << *dbStr++;
  cout << " = " << e << ','; _db(dbStr + 1, r...);
}
template<class S, class T>
ostream& operator<<(ostream& o, const map<S, T>& v) {
	o << "["; int i = 0;
	for (const pair<S, T>& pr : v) o << (!i++ ? "" : ", ") << "{"
	<< pr.fs << " : " << pr.sc << "}"; return o << "]";
}
template<template <class, class...> class S, class T, class... L>
ostream& operator<<(ostream& o, const S<T, L...>& v) {
	o << "["; int i = 0;
	for (const auto& e : v) o << (!i++ ? "" : ", ") << e;
	return o << "]";
}
template<class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& pr) {
	return o << "(" << pr.fs << ", " << pr.sc << ")";
}
ostream& operator<<(ostream& o, const string& s) {
	for (const char& c : s) o << c;
	return o;
}

template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
template<class T> using VVV = VV<V<T>>;
using ll = long long;
using pii = pair<int, int>;
using vi = V<int>;
using vii = V<pii>;
using vvi = VV<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using si = set<int>;
using usi = unordered_set<int>;

int N, M;
ll K;
V<ll> x, d;
V<bool> vis;


int main() {
	#ifdef LOCAL
	auto stTime = clock();
	freopen("in.txt", "r", stdin);
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	ios::sync_with_stdio(false);
	cout.precision(10);
	cin.tie(0);

	cin >> N;

	x.assign(N + 1, 0);
	d.assign(N, 0);

	for (int i = 1; i <= N; ++i)
		cin >> x[i];

	for (int i = 1; i <= N - 1; ++i)
		d[i] = x[i + 1] - x[i];

	vi P(N, 0);

	for (int i = 1; i <= N - 1; ++i)
		P[i] = i;

//	db(d);
//	db(P);

	cin >> M >> K;

	for (int i = 1; i <= M; ++i) {
		int ai;
		cin >> ai;
		swap(P[ai], P[ai - 1]);
	}

	db(P);
	db(K % (N - 1));

	vis.assign(N + 1, 0);

	V<ll> Ed(N + 1, 0);

	for (int i = 1; i <= N - 1; ++i) {
		int curr = i;
		vi cyc;
		while (!vis[curr]) {
			cyc.pb(curr);
			vis[curr] = true;
			curr = P[curr];
		}

		if (!cyc.empty()) {
			db(cyc);
		}

		for (int j = 0; j < sz(cyc); ++j)
			Ed[cyc[j]] = d[cyc[(j + K) % sz(cyc)]];
	}

	db(d);
	db(Ed);

	ll ans = x[1];

	for (int i = 1;; ++i) {
		cout << ans << '\n';
		if (i == N)
			break;
		ans += Ed[i];
	}



	#ifdef LOCAL
	cout << "\n\n\nExecution time: " <<
		(clock() - stTime) * 1e3 / CLOCKS_PER_SEC << " ms" << endl;
	#endif
	return 0;
}
