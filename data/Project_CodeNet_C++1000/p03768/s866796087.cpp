#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define rep(i,x) for(int (i)=1;(i)<=(x);(i)++)
#define repp(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
#define per(i,x,y) for(int (i)=(x);(i)>=(y);(i)--)
#define forn(i,x) for(int (i)=0;(i)<(x);(i)++)
#define foreach(i,x) for(auto i:x)
using namespace std;
typedef pair<int,int>pii;
int n,m,q;
vector<int>G[100010];
int v[100010],d[100010],c[100010],col[100010];
int now;
int used[100010];
inline void read(int &x){
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
}
inline void dfs(int x,int d){
	if(used[x]>=d)return;
	used[x]=d;
	if(!col[x])col[x]=now;
	foreach(to,G[x])if(d)dfs(to,d-1);
}
int main(){
	memset(used,-1,sizeof(used));
	read(n),read(m);
	for(int i=1,x,y;i<=m;i++){
		read(x),read(y);
		G[x].pb(y),G[y].pb(x);
	}
	read(q);
	rep(i,q)read(v[i]),read(d[i]),read(c[i]);
	for(int i=q;i;i--){
		now=c[i];
		dfs(v[i],d[i]);
		// rep(i,n)cout<<col[i]<<' ';
		// puts("");
	}
	rep(i,n)cout<<col[i]<<endl;
	return 0;
}
/*
7 7
1 2
1 3
1 4
4 5
5 6
5 7
2 3
2
6 1 1
1 2 2
*/