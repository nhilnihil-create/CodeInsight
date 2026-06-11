#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> P;
int N,M,q,a,b,u[100010],c[100010],d[100010];

int dp[100010][11] = {{0}};
vector<vector<int>> v(100010);


void bfs(int n,int d,int time){
	queue<P> Q;
	Q.push({n,d});
	for(int j=0;j<=d;j++){
		if(dp[n][j]==0) dp[n][j] = c[time];
	}
	while(!Q.empty()){
		P p = Q.front();
		int t = p.first,e = p.second;
		Q.pop();
		for(int i=0;i<v[t].size();i++){
			if(dp[v[t][i]][e-1]==0){
				for(int j=0;j<=e-1;j++){
					if(dp[v[t][i]][j]==0) dp[v[t][i]][j] = c[time];
				}
				if(e>1) Q.push({v[t][i],e-1});
			}
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> q;
	for(int i=1;i<=q;i++){
		cin >> u[i] >> d[i] >> c[i];
	}
	for(int i=q;i>=1;i--){
		bfs(u[i],d[i],i);
	}
	for(int i=1;i<=N;i++){
		cout << dp[i][0] << endl;
	}
}
