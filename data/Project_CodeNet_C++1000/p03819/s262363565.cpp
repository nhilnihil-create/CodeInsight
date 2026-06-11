#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int bm = 100002;
int BIT[bm];
void addp(int A) {
	while (A <= bm) {
		BIT[A]++;
		A += A & -A;
	}
}
void addn(int A) {
	while (A <= bm) {
		BIT[A]--;
		A += A & -A;
	}
}
int query(int A) {
	int ret = 0;
	while (A > 0) {
		ret += BIT[A];
		A -= A & -A;
	}
	return ret;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;
	int L[300001], ne[300001], he[100001] = {};
	rep1(i, N) {
		int lr;
		cin >> L[i] >> lr;
		lr -= L[i] - 1;
		ne[i] = he[lr];
		he[lr] = i;
	}

	int k = N;
	co(N);
	for (int j = he[1]; j; j = ne[j]) {
		addp(L[j]);
		addn(L[j] + 1);
		k--;
	}
	for (int i = 2; i <= M; i++) {
		int ans = k;
		for (int j = i; j <= M; j += i) {
			ans += query(j);
		}
		co(ans);
		for (int j = he[i]; j; j = ne[j]) {
			addp(L[j]);
			addn(L[j] + i);
			k--;
		}
	}

	Would you please return 0;
}