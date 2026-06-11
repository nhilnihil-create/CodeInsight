#include <bits/stdc++.h>
using namespace std;
vector<int> f(int n, int x, vector<vector<int>> &t) {
	vector<int> d(n), vis(n);
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int i = 0; i < t[now].size(); i++) {
			int nxt = t[now][i];
			if(vis[nxt]) continue;
			vis[nxt] = 1;
			d[nxt] = d[now] + 1;
			q.push(nxt);
		}
	}
	return d;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	int n; cin >> n;
	vector<vector<int>> t(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	vector<int> b = f(n, 0, t), w = f(n, n - 1, t);
	int res = 0;
	for(int i = 0; i < n; i++) {
		if(b[i] <= w[i]) res++;
		else res--;
	}
	cout << (res > 0 ? "Fennec" : "Snuke") << endl;
	return 0;	
}
