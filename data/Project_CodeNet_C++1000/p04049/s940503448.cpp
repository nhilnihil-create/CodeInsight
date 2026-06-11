#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e3 + 13, INF = 1e9 + 13;
int n, k, ans = INF, curans, lvl[maxN], curlvl[maxN], arr[maxN];
vector<int> adj[maxN];
bool cnt[maxN];
bool cmp (int i, int j) {
    if (lvl[i] != lvl[j])
	return lvl[i] > lvl[j];
    return i > j;
}

void dfs (int x, int p) {
    for (auto a : adj[x]) {
	if (a != p) {
	    lvl[a] = lvl[x] + 1;
	    dfs(a, x);
	}
    }
}	    

void solve (int x, int p) {
    for (auto a : adj[x]) {
	if (a != p && !cnt[a]) {
	    curlvl[a] = curlvl[x] + 1;
	    if (curlvl[a] > k)
		curans++;
	    solve(a, x);
	    //cout << a << " " << curlvl[a] << endl;
	}
    }
}

    
int main () {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
	int a, b;
	cin >> a >> b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }

    dfs(1, 1);
    iota(arr, arr + n, 1);
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
	int a = arr[i];
	curans = 0;
	memset(curlvl, 0, sizeof curlvl);
	//cout << a << endl;
	solve(a, a);
	cnt[a] = 1;
	ans = min(ans, curans + i);
	/*cout << curans << " " << i << endl;
	  cout << "////////" << endl;*/
    }

    cout << ans << endl;
}
