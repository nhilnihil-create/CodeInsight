#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}

template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}


signed main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>G(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].pb(b);
		G[b].pb(a);
	}

	vector<int>dist(n, -1);
	queue<int>que;
	dist[0] = 0;
	que.push(0);

	while (!que.empty()) {
		int v = que.front();
		que.pop();
		for (int nv : G[v]) {
			if (dist[nv] != -1) continue;
			dist[nv] = dist[v] + 1;
			que.push(nv);
		}
	}
	if (dist[n - 1] == 1 || dist[n - 1] == 2)print("POSSIBLE");
	else print("IMPOSSIBLE");
}