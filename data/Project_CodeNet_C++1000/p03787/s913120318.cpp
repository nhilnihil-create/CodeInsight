#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define llint long long

using namespace std;

llint N, M;
vector<llint> G[100005];
vector< pair<bool, llint> > cmp;
bool used[100005];
int color[100005];

bool check(int v)
{
	queue<int> Q;
	Q.push(v);
	color[v] = 1;
	
	int u;
	while(Q.size()){
		u = Q.front();
		Q.pop();
		for(int i = 0; i < G[u].size(); i++){
			if(color[G[u][i]] == color[u]) return false;
			if(color[G[u][i]] == color[u] * -1) continue;
			color[G[u][i]] = color[u] * -1;
			Q.push(G[u][i]);
		}
	}
	return true;
}

llint count(int v)
{
	used[v] = true;
	llint ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		ret += count(G[v][i]);
	}
	return ret+1;
}

int main(void)
{
	cin >> N >> M;
	llint u, v;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	bool bi; int cnt;
	llint bi_cnt = 0, nbi_cnt = 0, iso_cnt = 0;
	
	for(int i = 1; i <= N; i++){
		if(used[i]) continue;
		cmp.push_back( make_pair( bi = check(i), cnt = count(i) ) );
		if(cnt == 1) iso_cnt++;
		else{
			if(bi) bi_cnt++;
			else nbi_cnt++;
		}
	}
	
	llint ans = 0;
	for(int i = 0; i < cmp.size(); i++){
		if(cmp[i].second == 1) ans += N;
		else if(cmp[i].first) ans += bi_cnt*2 + nbi_cnt + iso_cnt * cmp[i].second;
		else ans += bi_cnt + nbi_cnt + iso_cnt * cmp[i].second;
	}
	
	cout << ans << endl;
	return 0;
}