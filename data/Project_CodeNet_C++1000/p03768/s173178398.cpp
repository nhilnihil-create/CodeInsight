#include<bits/stdc++.h>
using namespace std;
vector<int> a[100002];
int n,m,q,ans[100002],maindis[100002],v[100002],d[100002],c[100002];
void dfs(int k,int cc,int to){
	if(k<0){
		return;
	}
	if(k<=maindis[to]){
		return;
	}
	if(ans[to]==0){
		ans[to]=cc;
	}
	maindis[to]=k;
	for(int i=0;i<a[to].size();i++){
		dfs(k-1,cc,a[to][i]);
	}
}
int main(){
	cin>>n>>m;
	fill(maindis,maindis+100000,-1);
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=m;i++){
		int t1,t2;
		cin>>t1>>t2;
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	cin>>q;
	for(int i=q;i>0;i--){
		cin>>v[i]>>d[i]>>c[i];
	}
	for(int i=1;i<=q;i++){
		dfs(d[i],c[i],v[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
//	for(int i=1;i<=n;i++){
//		cout<<maindis[i]<<" ";
//	}
	return 0;
}