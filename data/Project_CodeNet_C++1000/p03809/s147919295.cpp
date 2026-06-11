#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,a[101000];
int f[110000];
vector<int> e[101000];
void dfs(int x,int dad){
	if(e[x].size()==1){f[x]=a[x];return;}
	ll s=0;int mx=0;
	for(int v:e[x]) if(v!=dad){
		dfs(v,x);
		mx=max(mx,f[v]);
		s+=f[v];
	}
	if(s<a[x]||s>2ll*a[x]){puts("NO");exit(0);}
	f[x]=2*a[x]-s;
	if(2*mx-s>f[x]){puts("NO");exit(0);}
}
int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	if(n==2){puts(a[1]==a[2]?"YES":"NO");return 0;}
	for(int i=1;i<n;i++){
		int x,y;read(x);read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(e[i].size()>1){
			dfs(i,0);
			if(!f[i])puts("YES");
			else puts("NO");
			return 0;
		}
	return 0;
}
