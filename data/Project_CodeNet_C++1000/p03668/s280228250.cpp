#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
vector<int> adj[114514];
int deg[114514],grundy[114514];
signed main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
		deg[x]++;
		deg[y]++;
	}
	queue<int> que;
	for(int i=2;i<=n;i++){
		if(deg[i]==1){
			que.push(i);
			grundy[i] = 0;
		}
	}
	while(!que.empty()){
		int id = que.front(); que.pop();
		for(int i=0;i<adj[id].size();i++){
			if(deg[adj[id][i]]>1 || adj[id][i]==1){
				int id2 = adj[id][i];
				grundy[id2] = grundy[id2]^(grundy[id]+1);
				deg[id2]--;
				if(deg[id2]==1 && id2!=1)que.push(id2);
			}
		}
	}
	if(grundy[1]==0){
		cout<<"Bob"<<endl;
	}
	else{
		cout<<"Alice"<<endl;
	}
	/* for(int i=1;i<=n;i++){
		cout<<i<<" "<<grundy[i]<<endl;
	}*/
	return 0;
}