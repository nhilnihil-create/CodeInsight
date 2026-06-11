#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int INF = TEN(9) * 2;
const ll MOD = TEN(9) + 7;

int main() {
	int N; cin >> N;
	vi T(N), A(N);
	vi mini(N, 1), maxi(N, INF);

	int la = -1;

	rep(i, N) {
		cin >> T[i];
	}
	rep(i, N) {
		cin >> A[i];
	}

	rep(i, N) {
		if (T[i] != la) {
			chmax(mini[i], T[i]);
			chmin(maxi[i], T[i]);
		} else {
			chmin(maxi[i], T[i]);
		}
		la = T[i];
	}

	la = -1;
	for (int i = N-1; i >= 0; --i) {
		if (A[i] != la) {
			chmax(mini[i], A[i]);
			chmin(maxi[i], A[i]);			
		} else {
			chmin(maxi[i], A[i]);
		}
		la = A[i];
	}

	ll ans = 1;
	rep(i, N) {
		if (mini[i] > maxi[i]) {
			ans = 0;
		} else {
			ans = ans * (maxi[i] - mini[i] + 1) % MOD;
		}
	}

	cout << ans << endl;

	return 0;
}