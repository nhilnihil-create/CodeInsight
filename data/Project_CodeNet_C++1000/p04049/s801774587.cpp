#include<bits/stdc++.h>
using namespace std;

int dist[2001];

vector<int> edge[2001];

int u[2001],v[2001];
int n,k;

int check_e(int x,int y){
	memset(dist,-1,sizeof dist);
	dist[x]=dist[y]=0;
	queue<int> q;
	q.push(x);q.push(y);
	while(!q.empty()){
		int now=q.front();q.pop();
		if(dist[now]==k/2)	continue;
		for(int it:edge[now])
			if(dist[it]==-1){
				dist[it]=dist[now]+1;
				q.push(it);
			}
	}
	int res=0;
	for(int i=1;i<=n;i++)
		res+=(dist[i]!=-1);
	return res;
}

int check_v(int x){
	memset(dist,-1,sizeof dist);
	dist[x]=0;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int now=q.front();q.pop();
		if(dist[now]==k/2)	continue;
		for(int it:edge[now])
			if(dist[it]==-1){
				dist[it]=dist[now]+1;
				q.push(it);
			}
	}
	int res=0;
	for(int i=1;i<=n;i++)
		res+=(dist[i]!=-1);
	return res;
	
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		edge[u[i]].emplace_back(v[i]);
		edge[v[i]].emplace_back(u[i]);
	}
	int ans=0;
	if(k&1)
		for(int i=1;i<n;i++)
			ans=max(ans,check_e(u[i],v[i]));
	else
		for(int i=1;i<=n;i++)
			ans=max(ans,check_v(i));
	cout<<n-ans<<endl;
}
