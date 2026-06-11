#include<bits/stdc++.h>
using namespace std;
struct node{
	int next,to;
}a[11451];
int n,m,x[2005],y[2005],cnt,head[2005],ll,da;
void add(int e,int r){
	a[++cnt].next=head[e];a[cnt].to=r;head[e]=cnt;
}
void dfs(int u,int fa,int deep){
	if(deep>m/2)return ;
	ll++;
	for(int i=head[u];i;i=a[i].next){
		if(a[i].to==fa)continue;
		dfs(a[i].to,u,deep+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>x[i]>>y[i];
		add(x[i],y[i]);add(y[i],x[i]);
	}
	if(m%2==0){
		for(int i=1;i<=n;i++){
			ll=0;
			dfs(i,0,0);
			da=max(da,ll);
		}
		cout<<n-da;
		return 0;
	}
	if(m%2==1){
		for(int i=1;i<n;i++){
			ll=0;
			dfs(x[i],y[i],0);
			dfs(y[i],x[i],0);
			da=max(da,ll);
		}
		cout<<n-da;
		return 0;
	}
}