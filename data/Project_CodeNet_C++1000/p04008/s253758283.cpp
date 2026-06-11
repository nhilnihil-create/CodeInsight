// Ala be zekrellah tatmaenolgholoob ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 1e5+9;
const ll mod = 1e9+7;

vector <int> g[maxn];
int a[maxn];
int k, res = 0;

int dfs (int v, int parent = -1) {
	int mx = 0;
	for (auto u : g[v]) 
		if (u - parent) {
			int cur = dfs(u, v);
			if ((v == 0 && cur == k) || (v != 0 && cur == k - 1))
				res++;
			else
				mx = max(mx, cur + 1);
		}
	return mx;
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		--a[i];
		if (i)
			g[a[i]].push_back(i);
		else
		if (a[i])
			res++;
	}
	dfs(0);
	cout << res << "\n";
}

