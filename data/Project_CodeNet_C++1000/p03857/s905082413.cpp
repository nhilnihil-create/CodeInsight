#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 * 1000 + 20;
int n, k, l;
vector <int> adj[2][maxn];
int vis[2][maxn], cnt_moalefe[2];
map <pair<int, int>, int> eshterak;

void input() {
    cin >> n >> k >> l;
	for(int i = 0, a, b; i < k; i++) {
        cin >> a >> b;
		adj[0][a].push_back(b);
		adj[0][b].push_back(a);
	}
	for(int i = 0, a, b; i < l; i++) {
		cin >> a >> b;
		adj[1][b].push_back(a);
		adj[1][a].push_back(b);
	}
}

void dfs(int v, int t) {
    vis[t][v] = cnt_moalefe[t];
    for (int i : adj[t][v])
        if (!vis[t][i])
            dfs(i, t);
}

int main() {    
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    input();
    for(int i = 1; i <= n; i++) {
		if(!vis[0][i]) {
            cnt_moalefe[0]++;
            dfs(i, 0);
        }
		if(!vis[1][i]) {
            cnt_moalefe[1]++;
            dfs(i, 1);
        }
	}
    for (int i = 1; i <= n; i++)
        eshterak[make_pair(vis[0][i], vis[1][i])]++;
    for (int i = 1; i <= n; i++) 
        cout << eshterak[make_pair(vis[0][i], vis[1][i])] << ' ';
    cout << endl;
    return 0;    
}

