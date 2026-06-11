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

int G[100001];
pair<int, int> E[200001];
pair<int, int>* P[100002];
int dfs(int A) {
	if (G[A] == 0) {
		int g = 0;
		G[A] = -1;
		for (auto p = P[A]; p < P[A + 1]; p++) {
			g ^= dfs((*p).second);
		}
		return G[A] = g + 1;
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	for (int i = 0; i < N + N - 2; i += 2) {
		int x, y;
		cin >> x >> y;
		E[i] = mp(x, y);
		E[i + 1] = mp(y, x);
	}
	sort(E, E + N + N - 2);
	int k = 0;
	rep(i, N + N - 2) {
		if (k != E[i].first) {
			k++;
			P[k] = E + i;
		}
	}
	P[N + 1] = E + N + N - 2;

	dfs(1);

	if (G[1] - 1) co("Alice");
	else co("Bob");

	Would you please return 0;
}
