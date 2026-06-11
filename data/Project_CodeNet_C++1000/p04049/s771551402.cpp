#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 10;
int d[N], n, u[N], v[N];
vector<int> adj[N];
bool mark[N];

void bfs(vector<int> e) {
	for (int i = 0; i < n; i++)
		mark[i] = false;
  	queue<int> q;
  	for (int i = 0; i < e.size(); i++) {
    	mark[e[i]] = true;
      	q.push(e[i]);
      	d[e[i]] = 0;
    }
  	while(q.size()) {
    	int root = q.front();
      	q.pop();
      	for (int i = 0; i < adj[root].size(); i++) {
        	if(!mark[adj[root][i]]) {
            	mark[adj[root][i]] = true;
              	d[adj[root][i]] = d[root] + 1;
           		q.push(adj[root][i]);
            }
        }
    }

}

int main() {
	int k;
  	cin >> n >> k;
  	for (int i = 1; i < n; i++) {
		cin >> u[i] >> v[i];
      	u[i]--, v[i]--;
      	adj[u[i]].push_back(v[i]);
      	adj[v[i]].push_back(u[i]);
    }
  	int ans = n;
  	if(k % 2 == 0) {
    	for (int i = 0; i < n; i++) {
        	vector<int> e;
          	e.push_back(i);
          	bfs(e);
          	int cnt = 0;
          	for (int j = 0; j < n; j++)
            	if(d[j] > k / 2)
                  cnt++;
         	ans = min(ans, cnt);
        }
    }
  	else {
    	for (int i = 1; i < n; i++) {
        	vector<int> e;
          	e.push_back(v[i]);
          	e.push_back(u[i]);
          	bfs(e);
          	int cnt = 0;
          	for (int j = 0; j < n; j++)
            	if(d[j] > k / 2)
                	cnt++;
          	ans = min(ans, cnt);
    	}
    }
   	cout << ans << endl;
    return 0;
}
