#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define ll long long
using namespace std;
int n,m,a[100100];
ll c[2][100100],s,t,ans;
void add(int id,int le,int ri,ll val){
	for(;ri;ri-=lowbit(ri)) c[id][ri]+=val;
	le--;if(le==0) return;
	for(;le;le-=lowbit(le)) c[id][le]-=val;
}
ll get(int id,int x){
	ll tot=0;
	for(;x<=m;x+=lowbit(x)) tot+=c[id][x];
	return tot;
}
ll gans(int x){
	ll ans=0;
	ans+=get(0,x);
	ans+=(ll)(x)*get(1,x);
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		s=a[i];t=a[i+1];
		if(s<t){
			add(0,1,s,t-s);
			add(0,s+1,t,t+1);
			add(1,s+1,t,-1);
			add(0,t+1,m,t-s);
		}
		else{
			add(0,1,t,t+1);
			add(1,1,t,-1);
			add(0,t+1,s,t+m-s);
			add(0,s+1,m,t+m+1);
			add(1,s+1,m,-1);
		}
	}
	ans=1e18;
	for(int i=1;i<=m;i++) ans=min(ans,gans(i));
	cout<<ans<<endl;
	return 0;
}
