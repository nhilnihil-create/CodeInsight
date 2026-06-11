#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2000 + 4;
int n, k;
vector< int> adj[MAXN];
pair< int, int>  edd[MAXN];
int h[MAXN], par[MAXN];
bool mark[MAXN];

void dfs( int u){
	mark[u] = true;
	for( int i = 0; i < adj[u].size(); i ++){
		int v = adj[u][i];
		if(!mark[v]){
			h[v] = h[u] + 1;
			dfs( v );
		}
	}
	return;
	
}
 
void clnn(){
	for( int i = 0 ; i < n; i ++){
		mark[i] = false;
		h[i] = 0;
		par[i] = 0;
	}
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	int ans = n;
	for( int i = 0; i < n - 1 ; i ++){
		int a, b;
		cin >> a >> b;
		a --, b --;
		adj[a].push_back( b );
		adj[b].push_back( a );
		edd[i] = {a, b};
	}
	if(k % 2 == 0){
		for(int i = 0; i < n; i++){
			clnn();
			dfs(i);
			int tmp = 0;
			for(int j = 0 ; j < n; j++){	
				if(h[j] > k/2){
					tmp ++;
				}
			}
			ans = min(ans, tmp);
		}
	}
	else{
		for(int i = 0; i < n - 1; i ++){
			clnn();
			int a, b;
			a = edd[i].first;
			b = edd[i].second;
			mark[a] = true;
			mark[b] = true;
			dfs(a);
			dfs(b);
			int tmp = 0;
			for(int j = 0; j <  n; j++){	
				if(h[j] > k/2){
					tmp++;
				}
			}
			ans = min(ans, tmp);	
		}	
	}
	cout << ans << endl;
		
	
 
 
	return 0;
}