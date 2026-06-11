#include<bits/stdc++.h>
using namespace std;
int n,k,ans,lim,cnt,mn;
vector<int> adj[2002];
vector<pair<int,int> > e;
int dis[2002][2];
void dfs(int v,int par,int r){
	for (int i:adj[v]){
		if (i != par){
			dis[i][r] = dis[v][r]+1;
			dfs(i,v,r);		
		}
	}	
}
int main(){
	cin >> n >> k;
	for (int i = 1; i < n; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		e.push_back({a,b});
	}
	mn = INT_MAX;
	if (k%2==0){
		lim = k/2;
		for (int i = 1; i <= n; i++){
			cnt = 0;
			dis[i][0]= 0;
			dfs(i,i,0);
			for (int i = 1; i <= n; i++)
			if (dis[i][0] > lim)
				cnt ++;
			mn = min(mn,cnt);	
		}		
	}
	else {
		lim = k/2;
		for (auto i:e){
			int v1 = i.first, v2 = i.second;
			cnt = 0;
			dis[v1][0] = 0;
			dfs(v1,v1,0);
			dis[v2][1] = 0;
			dfs(v2,v2,1);
			for (int i = 1; i <= n; i++)
			if (min(dis[i][0],dis[i][1]) > lim)
				cnt ++;
			mn = min(mn,cnt); 	
		}
	}
	cout << mn;      
}