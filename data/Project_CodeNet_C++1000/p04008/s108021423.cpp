#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
int n,K,ans,a[1010101],dep[1010101];
vector<int> e[1010101];
int dfs(int u){
	int mx=dep[u];
	for (auto v:e[u]){
		dep[v]=dep[u]+1;
		mx=max(mx,dfs(v));
	}
	int dis=mx-dep[u]+(u!=1);
	if (dis>=K&&a[u]!=1) ans++,mx=-1;
	return mx;
}
signed main(){
	n=read(),K=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (a[1]!=1) a[1]=1,ans++;
	for (int i=2;i<=n;i++) e[a[i]].push_back(i);
	dfs(1);
	cout<<ans;
	return 0;
}

