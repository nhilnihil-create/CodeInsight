#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+10;
int n,col[N],dep[N],f[N],num[5];
vector<int> g[N],v;
inline void add(int a,int b){g[a].push_back(b),g[b].push_back(a);}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1; f[x]=fa;
	for(int to:g[x])	if(to!=fa)	dfs(to,x); 
}
void upd(int x,int co){
	for(int to:g[x])	if(col[to]==-1)	col[to]=co,upd(to,co);
}
signed main(){
	cin>>n; memset(col,-1,sizeof col);
	for(int i=1,a,b;i<n;i++)	scanf("%d %d",&a,&b),add(a,b);
	dfs(1,0);
	int now=n,cnt=dep[now]/2;
	while(now){
		if(cnt>0)	col[now]=0,cnt--;
		else	col[now]=1; now=f[now];
	}
	for(int i=1;i<=n;i++)	if(col[i]!=-1)	upd(i,col[i]);
	for(int i=1;i<=n;i++)	num[col[i]]++;
	if(num[1]>num[0])	puts("Fennec");
	else	puts("Snuke");
	return 0;
}
