#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> G[100005];
int depth[100005];
int pre[17][100005];
int prek[100005];
bool mark[100005];
vector<pair<int, int> > vec;

void depdfs(int v, int dep)
{
	depth[v] = dep;
	for(int i = 0; i < G[v].size(); i++){
		depdfs(G[v][i], dep+1);
	}
}

void markdfs(int v)
{
	mark[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(mark[G[v][i]]) continue;
		markdfs(G[v][i]);
	}
}

int main(void)
{
	int ans = 0;
	cin >> n >> k;
	
	int a;
	cin >> a;
	if(a != 1) ans++;
	for(int i = 2; i <= n; i++){
		cin >> a;
		G[a].push_back(i);
	}
	
	if(k > n){
		cout << ans << endl;
		return 0;
	}
	
	depdfs(1, 0);
	for(int i = 1; i <= n; i++) vec.push_back(make_pair(depth[i], i));
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			pre[0][G[i][j]] = i;
		}
	}
	pre[0][1] = -1;
	
	for(int i = 1; i < 17; i++){
		for(int j = 1; j <= n; j++){
			pre[i][j] = pre[i-1][pre[i-1][j]];
		}
	}
	for(int i = 1; i <= n; i++){
		int p = i;
		for(int j = 0; j < 17; j++){
			if((k-1) & (1<<j)) p = pre[j][p];
		}
		prek[i] = p;
	}
	
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].first <= k) break;
		int v = vec[i].second;
		if(mark[v]) continue;
		ans++;
		markdfs(prek[v]);
	}
	
	cout << ans << endl;
	return 0;
}