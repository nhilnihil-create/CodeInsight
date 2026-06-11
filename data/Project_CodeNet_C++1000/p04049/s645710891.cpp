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

int D[2001][2001];
vector<int> E[2001];
void dfs(int v, int r, int d) {
	D[r][v] = d;
	for (int to : E[v]) {
		if (D[r][to] < 0) dfs(to, r, d + 1);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, K;
	cin >> N >> K;
	rep(i, N - 1) {
		int a, b;
		cin >> a >> b;
		E[a].pb(b);
		E[b].pb(a);
	}

	rep1(i, N) rep1(j, N) D[i][j] = -1;
	rep1(i, N) dfs(i, i, 0);

	if (K % 2 == 0) {
		int kotae = N;
		rep1(i, N) {
			int kazu = 0;
			rep1(j, N) if (D[i][j] > K / 2) kazu++;
			kotae = min(kotae, kazu);
		}
		co(kotae);
	}
	else {
		int kotae = N;
		rep1(i, N) {
			for (int j : E[i]) {
				if (i < j) {
					int kazu = 0;
					rep1(k, N) if (min(D[j][k], D[i][k]) > K / 2) kazu++;
					kotae = min(kotae, kazu);
				}
			}
		}
		co(kotae);
	}

	Would you please return 0;
}