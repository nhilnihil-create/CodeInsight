#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
const int N=2005;
int n,sum=0,dia,dem[N],max1;
vector<int> adj[N];
void dfs(int x,int p,int dis){
	int now=0;
	for(int i=0;i<adj[x].size();i++){
		if(adj[x][i]!=p){
			if(dis+1<=dia/2){
				sum++;
				dfs(adj[x][i],x,dis+1);
				dem[x]+=dem[adj[x][i]];
			}
			else{
				if(dis+1==(dia+1)/2){
					dem[x]++;
					dem[adj[x][i]]++;
				}
			}
		}
	}
}
int main(){
	int i,j,k,ans;
	cin>>n>>dia;
	ans=n+1;
	for(i=1;i<n;i++){
		cin>>j>>k;
		adj[j].push_back(k);
		adj[k].push_back(j);
	}
	for(i=1;i<=n;i++){
		memset(dem,0,sizeof(dem));
		sum=1;
		max1=0;
		dfs(i,i,0);
		for(j=0;j<adj[i].size();j++){
			max1=max(max1,dem[adj[i][j]]);
		}
		ans=min(ans,n-sum-max1);
	}
	cout<<ans;
}