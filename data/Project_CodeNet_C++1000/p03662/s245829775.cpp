#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> t;
vector<int> wfs(int x) {
	vector<bool> vis(n, false);
	vector<int> d(n);
	vis[x] = true;
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for(int i = 0; i < t[cur].size(); i++) {
			int nxt = t[cur][i];
			if(vis[nxt]) continue;
			vis[nxt] = true;
			d[nxt] = d[cur] + 1;
			q.push(nxt);
		}
	}
	return d;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	
	cin >> n;
	t.resize(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	vector<int> f = wfs(0), s = wfs(n - 1);
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(f[i] <= s[i]) cnt++;
		else cnt--;
	}
	cout << (cnt > 0 ? "Fennec" : "Snuke") << endl;
	return 0;	
}