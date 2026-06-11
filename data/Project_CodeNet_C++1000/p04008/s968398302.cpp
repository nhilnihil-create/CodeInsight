#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 13;
int n, a[maxN], lvl[maxN], ans, k;
vector<int> adj[maxN];
void dfs (int x, int par) {
    lvl[x] = 1;
    for (auto a : adj[x]) {
	if (a != par) {
	    dfs(a, x);
	    lvl[x] = max(lvl[x], lvl[a] + 1);
	}
    }
    if (lvl[x] >= k && par != 0) {
	ans++;
	lvl[x] = 0;
    }
}

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	a[i]--;
    }

    if (a[0] != 0)
	ans++;
    for (int i = 1; i < n; i++)
	adj[a[i]].push_back(i);

    dfs(0, 0);
    cout << ans << endl;
}
   
