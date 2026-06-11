#include <bits/stdc++.h>
using namespace std;
    
const int N = 2005;
const int maxn = 1000 * 100 * 3; 
	   
vector <int> v[N];
int vis[N];
int cnt, cnt2;
int n, k;

struct bian {
    int x, y;
}vv[N];
    
void dfs(int p, int deep) {
    if(deep > k / 2)
    	cnt++;
    int len = v[p].size();
    vis[p] = 1;
    for(int i = 0; i < len; i++){ 
    	if(vis[v[p][i]])
			continue;
    	dfs(v[p][i], deep + 1);
	}
	vis[p]=0;
}
    
int main() {
    int x, y;
    cin >> n >> k;
    for(int i = 0; i < N; i++) {
    	v[i].clear();
    	vis[i] = 0;
    }
    for(int i = 1; i <= n - 1; i++) {
    	cin >> x >> y;
		v[x].push_back(y);
    	v[y].push_back(x);
    	vv[i].x = x;
		vv[i].y = y;
    }
    int ans = maxn;
    if(k % 2) {
    	for(int i = 1; i <= n - 1; i++) {
    		cnt = 0;
    		vis[vv[i].x] = 1;
    		dfs(vv[i].y, 0);
    		vis[vv[i].x] = 0;
    		vis[vv[i].y] = 1;
    		dfs(vv[i].x, 0);
    		vis[vv[i].y] = 0;
    		ans = min(ans, cnt);
    	}
    }
    else {
    	for(int i = 1; i <= n; i++) {
    		cnt = 0;
			cnt2 = 0;
    		dfs(i, 0);
    		ans = min(cnt, ans);
    	}
    }
    cout << ans;
	return 0;
}
