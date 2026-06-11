# include<bits/stdc++.h> 
#define ll long long
using namespace std;

bool visited[200005];
vector<vector<int>> edge;
void dfs(int i){
	visited[i] = 1;
	for(int j = 0; j<edge[i].size();j++){
		if(!visited[edge[i][j]]){
			dfs(edge[i][j]);
		}
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n,m,a,b;
	cin>>n>>m;
	edge.resize(n+1);
	for(int i = 0; i<m; i++){
		cin>>a>>b;
		edge[a].push_back(b);
	}
	for(int i = 0; i< edge[1].size();i++){
		for(int j = 0; j < edge[edge[1][i]].size();j++){
			if(edge[edge[1][i]][j] == n){
				cout<<"POSSIBLE\n";
				return 0;
			}
		}
	}

	cout<<"IMPOSSIBLE\n";
	

}