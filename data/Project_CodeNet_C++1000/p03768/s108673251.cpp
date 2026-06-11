#include <iostream>
#include <vector>
#define MAX 100010

using namespace std;
vector<int> G[MAX];
int dp[MAX][12],v[MAX],d[MAX],c[MAX];

void dfs(int v, int d, int c){
	if(d>=0 && !dp[v][d]){
		dp[v][d] = c;
		dfs(v,d-1,c);
		for(int i=0;i<G[v].size();i++){
			dfs(G[v][i],d-1,c);
		}
	}
}

int main(){
	int i,j,n,m,q;
	cin >> n >> m ;
	for(i=0;i<m;i++){
		int s,t;
		cin >> s >> t;
		s--; t--;
		G[s].push_back(t);
		G[t].push_back(s);
	}
	cin >> q;
	for(i=0;i<q;i++){
		cin >> v[i] >> d[i] >> c[i];
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<=10;j++){
			dp[i][j] = 0;
		}
	}
	
	
	for(i=q-1;i>=0;i--){
		dfs(v[i]-1,d[i],c[i]);
	}
	
	for(i=0;i<n;i++){
		cout << dp[i][0] << endl;
	}
}
	