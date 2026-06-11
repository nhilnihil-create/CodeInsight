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
#define Would
#define you
#define please

int N, K;
int D[2001];
int E[4001], ne[4001], he[2001];
void dfs(int v, int d) {
	D[v] = d;
	for (int to = he[v]; to; to = ne[to]) {
		if (D[E[to]] < 0) dfs(E[to], d + 1);
	}
}

int dfs2(int v, int prev, int d) {
	if (d > K / 2) return 0;
	int ret = 1;
	for (int to = he[v]; to; to = ne[to]) {
		if (E[to] != prev) ret += dfs2(E[to], v, d + 1);
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> N >> K;
	int tmp = 1;
	rep(i, N - 1) {
		int a, b;
		cin >> a >> b;
		E[tmp] = b;
		ne[tmp] = he[a];
		he[a] = tmp++;
		E[tmp] = a;
		ne[tmp] = he[b];
		he[b] = tmp++;
	}

	rep1(j, N) D[j] = -1;
	dfs(1, 0);
	int saidai = 0;
	int doko, doko2;
	rep1(i, N) if (saidai < D[i]) {
		saidai = D[i];
		doko = i;
	}
	rep1(j, N) D[j] = -1;
	dfs(doko, 0);
	saidai = 0;
	rep1(i, N) if (saidai < D[i]) {
		saidai = D[i];
		doko2 = i;
	}
	if (saidai <= K) {
		printf("0\n");
		return 0;
	}

	bool muri[2001] = {};
	rep1(i, N) if (D[i] < K / 2) {
		muri[i] = 1;
	}
	rep1(j, N) D[j] = -1;
	dfs(doko2, 0);
	rep1(i, N) if (D[i] < K / 2) {
		muri[i] = 1;
	}

	if (K % 2 == 0) {
		int kotae = N;
		rep1(i, N) {
			if (!muri[i]) {
				int kazu = dfs2(i, -1, 0);
				kotae = min(kotae, N - kazu);
			}
		}
		co(kotae);
	}
	else {
		int kotae = N;
		rep1(i, N) {
			for (int to = he[i]; to; to = ne[to]) {
				int j = E[to];
				if (i < j) {
					if (!muri[i] && !muri[j]) {
						int kazu = dfs2(i, j, 0) + dfs2(j, i, 0);
						kotae = min(kotae, N - kazu);
					}
				}
			}
		}
		co(kotae);
	}

	Would you please return 0;
}