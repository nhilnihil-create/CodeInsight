#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	int n;
	cin >> n;
	vector<vector<int>> t(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	vector<int> b(n), w(n), vis(n);
	vis[0] = 1;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int i = 0; i < t[now].size(); i++) {
			int nxt = t[now][i];
			if(vis[nxt]) continue;
			vis[nxt] = 1;
			b[nxt] = b[now] + 1;
			q.push(nxt);
		}
	}
	fill(vis.begin(), vis.end(), 0);
	vis[n - 1] = 1;
	q.push(n - 1);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int i = 0; i < t[now].size(); i++) {
			int nxt = t[now][i];
			if(vis[nxt]) continue;
			vis[nxt] = 1;
			w[nxt] = w[now] + 1;
			q.push(nxt);
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
			if(b[i] <= w[i]) cnt++;
			else cnt--;
	}
	if(cnt > 0) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
	
	return 0;	
}
