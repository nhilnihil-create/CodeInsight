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

//二部グラフかぁ

pair<int, int> E[400001];
int H[100001], D[100001];
bool root[100001], dame[100001], nE[100001];
void dfs(int p, int d, int rt) {
	if (D[p]) {
		if ((d + D[p]) & 1) dame[rt] = true;
		return;
	}
	D[p] = d;
	int tmp = 0;
	for (int i = H[p]; i; i = E[i].second) {
		tmp++;
		dfs(E[i].first, d + 1, rt);
	}
	if (tmp == 0) nE[p] = true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		E[i + i + 1] = mp(a, H[b]);
		H[b] = i + i + 1;
		E[i + i + 2] = mp(b, H[a]);
		H[a] = i + i + 2;
	}

	rep1(i, N) {
		if (!D[i]) {
			root[i] = true;
			dfs(i, 1, i);
		}
	}

	ll x = 0, y = 0, z = 0;
	rep1(i, N) {
		if (root[i]) {
			if (nE[i]) z++;
			else if (dame[i]) y++;
			else x++;
		}
	}

	ll kotae = x * x + (x + y) * (x + y) + 2 * N * z - z * z;
	co(kotae);



	Would you please return 0;
}