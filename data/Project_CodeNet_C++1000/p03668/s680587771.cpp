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
vector<int> E[100001];
int dfs(int A) {
	int g = 0;
	G[A] = -1;
	for (auto i : E[A]) {
		if (G[i] != -1) g ^= dfs(i);
	}
	return G[A] = g + 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	rep(i, N - 1) {
		int x, y;
		cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}

	dfs(1);

	if (G[1] - 1) co("Alice");
	else co("Bob");

	Would you please return 0;
}