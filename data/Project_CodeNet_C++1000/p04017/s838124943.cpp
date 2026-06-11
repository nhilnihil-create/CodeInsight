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
template<class T, class... A> void print(const T& first, const A& ... rest) { cout << first << " "; print(rest...); }
struct PreMain { PreMain() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); } } premain;


int main() {
	int N;
	cin >> N;

	std::vector<ll> X(N);
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}

	int L;
	cin >> L;

	//尺取り法で各ホテルからLでいけるホテルを探す
	std::vector<std::vector<int>> H(N, std::vector<int>(20));
	int r = 0;
	for (int l = 0; l < N; l++) {
		while (r < (N - 1)) {
			if (L < (X[r + 1] - X[l])) {
				break;
			}
			r++;
		}
		H[l][0] = r;
	}

	//ダブリング
	for (int k = 1; k < 20; k++) {
		for (int i = 0; i < N; i++) {
			H[i][k] = H[H[i][k - 1]][k - 1];
		}
	}

	int Q;
	cin >> Q;

	for (int q = 0; q < Q; q++) {
		int a, b;
		cin >> a >> b;
		if (a > b) std::swap(a, b);
		a -= 1;
		b -= 1;

		int ans = 0;
		for (int k = 19; 0 <= k; k--) {
			if (H[a][k] < b) {
				a = H[a][k];
				ans += (1 << k);
			}
		}

		print(ans + 1);
	}


	return 0;
}
