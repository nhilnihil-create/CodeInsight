#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
const int MAXN = 100050;
const int MAXM = 400500;
bool vis[MAXN];
int h[MAXN],nx[MAXM],to[MAXM],tot,rk[MAXN];
int color[MAXN],n,m;
void add_edge(int x,int y){to[++tot]=y;nx[tot]=h[x];h[x]=tot;rk[x]++;}
void link(int x,int y){add_edge(x,y);add_edge(y,x);}
bool dfs(int x,int y){
	if(color[x]&&3-color[x]!=y)return 0;
	if(vis[x])return 1;
	vis[x]=1;
	color[x]=3-y;
	bool tmp=true;
	for(int i=h[x];i;i=nx[i]){
	//	if(vis[to[i]])continue;
		tmp&=dfs(to[i],color[x]);
	}
	return tmp;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	rep(i,1,m){
		int a,b;
		cin>>a>>b;
		link(a,b);
	}
	ll cnt1=0,cnt2=0,cnt3=0;
	rep(i,1,n){
		if(!rk[i])cnt1++;
		else if(!color[i]){
			int ret = dfs(i,1);
			if(ret == 0)
				cnt3++;
			else 
				cnt2++;
		}
	
	}
//	cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
	cout<<cnt1*cnt1+2LL*cnt1*(n-cnt1)+cnt2*cnt2*2+cnt2*cnt3*2+cnt3*cnt3;
	return 0;
}
