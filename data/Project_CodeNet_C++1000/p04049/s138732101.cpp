#include <iostream>
#include <cstring>
#define N 4001
using namespace std;
typedef long long ll;
struct tree{
	ll lf,rt;
}a[N];
ll head[N];
bool vis[N];
ll n,k;
ll num,ans,tot;
inline void fstart(ll lf,ll rt){
	num++;
	a[num].rt=rt;
	a[num].lf=head[lf];
	head[lf]=num;
}
inline void dfs(ll x,ll step){
	register int i,j;
	if(step>k/2)return ;
	for(i=head[x];i!=0;i=a[i].lf){
		ll p=a[i].rt;
		if(!vis[p])vis[p]=true,dfs(p,step+1),tot++;
	}
}
main(){
	register int i,j;
	cin>>n>>k;
	for(i=1;i<n;i++){
		ll lf,rt;
		cin>>lf>>rt;
		fstart(lf,rt);
		fstart(rt,lf);
	}
	if(k%2==0){
		for(i=1;i<=n;i++){
			memset(vis,false,sizeof(vis));
			vis[i]=true;
			tot=1;
		    dfs(i,1);
		    ans=max(ans,tot);
		}
	}
	else{
		k--;
		for(i=1;i<=n;i++){
			for(j=head[i];j!=0;j=a[j].lf){
				memset(vis,false,sizeof(vis));
				ll p=a[j].rt;
				vis[i]=true;vis[p]=true;
				tot=2;
				dfs(i,1);dfs(p,1);
				ans=max(ans,tot);
			}
		}
	}
	cout<<n-ans<<endl;
	return 0;
}