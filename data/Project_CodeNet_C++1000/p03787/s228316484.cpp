#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,m,tag[101000],dep[101000],s[2],sum[101000];
ll ans;
vector<int> e[101000];
void dfs(int x,int deep,int p){
	dep[x]=deep;
	sum[p]++;
	for(int&v:e[x])
		if(!dep[v]) dfs(v,deep+1,p);
		else if(dep[v]%2==dep[x]%2) tag[p]=1;
}
int main(){
	read(n);read(m);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int res=0;
	for(int i=1;i<=n;i++)
		if(!dep[i]){
			dfs(i,1,i);
			if(sum[i]==1) res++;
			else s[tag[i]]++;
		}
	ans+=1ll*s[1]*s[1]+2ll*s[1]*s[0]+2ll*s[0]*s[0]+1ll*res*res+2ll*res*(n-res);
	cout<<ans<<'\n';
	return 0;
}
