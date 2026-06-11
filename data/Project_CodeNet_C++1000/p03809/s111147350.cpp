#include <bits/stdc++.h>
using namespace std;
const int maxn = 123456;
vector<int> e[maxn];
int cs[maxn];
void bad(){
	cout << "NO" << endl;
	exit(0);
}
vector<int> eds;
int dfs(int u, int v){
	int vis = 0, mx = 0; long long sum = 0;
	for(int to : e[u]) if(to != v) {
		int val = dfs(to, u);
		sum += val;
		mx = max(mx, val);
		vis++;
	}
	if(vis == 0){
		return cs[u];
	}
	int expec = min(2, (int)e[u].size()) * cs[u];
	if(cs[u] > sum || expec < sum || cs[u] < mx) bad();
	int up = expec - sum;
	eds.push_back(up);
	return up;
}
int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> cs[i];
	for(int i = 0; i < n - 1; i++){
		int x, y; cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int ch = -1;
	for(int i = 1; i <= n; i++) if(e[i].size() != 1) ch = i;
	if(ch == -1){
		if(cs[1] != cs[2]) bad();
		else cout << "YES" << endl;
		return 0;
	}
	if(dfs(ch, 0)) bad();
	cout << "YES" << endl;
	return 0;
}
