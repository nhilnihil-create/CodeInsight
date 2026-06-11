#include<bits/stdc++.h>
using namespace std;
vector<int>v[3020];
int dep[3020];
int n,ans,d,k;
int p[3000][2],miner;
void dfs(int fath,int x){
	dep[x]=dep[fath]+1;
	if(dep[x]>d)ans++;
	for(int i=0;i<v[x].size();i++){
		int dot=v[x][i];	
		if(dot!=fath)dfs(x,dot);
	}
}
void ad(int x,int y){
	v[x].push_back(y);	
	v[y].push_back(x);
}
int main(){
	//freopen("p.in","r",stdin);
	//freopen("p.out","w",stdout);
	miner=3000;
	cin>>n>>k;
	for(int i=1;i<n;i++){
	cin>>p[i][0]>>p[i][1];	
	ad(p[i][0],p[i][1]);
	}
	if(k%2==0){
	d=k/2;
	for(int i=1;i<=n;i++){
	ans=0;
	memset(dep,0,sizeof(dep));
	dep[0]=-1;
	dfs(0,i);
	miner=min(miner,ans);
	}}
	if(k%2){
	d=k/2;	
	for(int i=1;i<n;i++){
	ans=0;
	memset(dep,0,sizeof(dep));
	dep[p[i][0]]=-1;
	dfs(p[i][0],p[i][1]);
	memset(dep,0,sizeof(dep));
	dep[p[i][1]]=-1;
	dfs(p[i][1],p[i][0]);
	miner=min(miner,ans);
	}
	}
	cout<<miner;
	return 0;
}