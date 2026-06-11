#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <list>
#include <map>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define fi first
#define se second
#define pb push_back
//#define mp make_pair
#define rep(i,n) for(register int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int dx[]={0,1,-1,0},dy[]={1,0,0,-1};
//const int MOD=998244353;
const int N=2e5+10;

inline int read(){
	int ww=1,xx=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') ww=-ww;ch=getchar();}
	while(isdigit(ch)){xx=(xx<<1)+(xx<<3)+(ch^48);ch=getchar();}
	return ww*xx;
}

int n=read();
int head[N];
int cnt;
int dist1[N],dist2[N],ans;

struct Edge{
	int to,nxt;
}ed[N];

void add_edge(int a,int b){
	ed[++cnt].to=b;
	ed[cnt].nxt=head[a];
	head[a]=cnt;
}

void dfs1(int u,int p){
	for(int i=head[u];i!=-1;i=ed[i].nxt){
		int v=ed[i].to;
		if(v!=p){
			dist1[v]=dist1[u]+1;
			dfs1(v,u);
		}
	}
}

void dfs2(int u,int p){
	for(int i=head[u];i!=-1;i=ed[i].nxt){
		int v=ed[i].to;
		if(v!=p){
			dist2[v]=dist2[u]+1;
			dfs2(v,u);
		}
	}
}

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int i=1;i<=n;i++) head[i]=-1;
	for(int i=1;i<n;i++){
		int fr,to;
		fr=read();
		to=read();
		add_edge(fr,to);
		add_edge(to,fr);
	}
	dist1[1]=0;
	dist2[n]=0;
	dfs1(1,-1);
	dfs2(n,-1);
	for(int i=1;i<=n;i++)
		if(dist1[i]<=dist2[i])
			ans++;
	if(ans>n-ans) puts("Fennec");
	else puts("Snuke");
	return 0;
}
/*
7
3 6
1 2
3 1
7 4
5 7
1 4

4
1 4
4 2
2 3
*/