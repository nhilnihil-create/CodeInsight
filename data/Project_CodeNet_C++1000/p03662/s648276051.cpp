#include <bits/stdc++.h>
#define MAXN 100100
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

int n, p[MAXN], dist;
set<int> g[MAXN];

void dfs(int x, int pa, int d){
	p[x] = pa;
	if(x == n) dist = d;
	for(auto i : g[x]){
		if(i == pa) continue;
		dfs(i, x, d + 1);
	}
}

int dfs1(int x, int pa){
	int s = 0;
	for(auto i : g[x]){
		if(i == pa) continue;
		s += dfs1(i, x);
	}
	return s + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++){
  		int a, b;
  		cin >> a >> b;
  		g[a].insert(b);
  		g[b].insert(a);
    }
    dfs(1, -1, 0);
    //cout << dist << endl;
    int x = n;
    for(int i = 0; i < (dist - 1) / 2; i++){
    	x = p[x];
    }
    g[x].erase(p[x]);
    g[p[x]].erase(x);
    int a = dfs1(1, -1);
    int b = dfs1(n, -1);
    if(a > b) cout << "Fennec";
    else cout << "Snuke";
}