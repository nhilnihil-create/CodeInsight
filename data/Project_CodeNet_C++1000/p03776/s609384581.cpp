#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

//#define INF (1e10)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x) { cout << x << endl; }
template<class T, class... A> void print(const T& first, const A& ... rest) { cout << first << " "; prll(rest...); }
struct PreMain { PreMain() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); } } premain;

ull comb(int n, int r) {
	std::vector<std::vector<ull>> v(n + 1, std::vector<ull>(n + 1, 0));
	for (int i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (int j = 1; j < v.size(); j++) {
		for (int k = 1; k < j; k++) {
			v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
		}
	}
	return v[n][r];
}

int main() {
	int N, A, B;
	cin >> N >> A >> B;	

	vector<ull> V(N);
	REP(i, N) cin >> V[i];
	sort(V.rbegin(), V.rend());

	double s = 0;
	REP(i, A) s += V[i];

	print(s / A);

	ull a = 0;
	ull b = 0;
	REP(i, A) {
		if (V[i] == V[A - 1]) {
			a++;
		}
	}
	REPN(i, A, N) {
		if (V[i] == V[A - 1]) {
			b++;
		}
	}

	if (a == A) {
		//すべて同じ値だったらB個使ってもいい
		ull ans = 0;
		REPN(j, A, min(static_cast<ull>(B), (a + b)) + 1) {
			ans += comb((a + b), j);
		}
		print(ans);
	}
	else {
		print(comb((a + b), a));
	}

	return 0;
}
