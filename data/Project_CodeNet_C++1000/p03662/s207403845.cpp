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

int n;
int num[N];
int q[N];
int head[N];
int cnt,tmp;
bool f;
int ans;

struct Edge{
	int to,nxt;
}ed[N];

void add_edge(int a,int b){
	ed[++cnt].to=b;
	ed[cnt].nxt=head[a];
	head[a]=cnt;
}

void dfs(int u,int p){
//	printf("%d ",u);
	if(!f) q[tmp++]=u;
	if(u==n) f=true;
	for(int i=head[u];i!=-1;i=ed[i].nxt){
		int v=ed[i].to;
		if(v!=p){
			dfs(v,u);
			num[u]+=num[v]+1;
		}
	}
	if(!f) --tmp;
	return ;
}

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	memset(head,-1,sizeof(head));
	n=read();
	for(int i=1;i<n;i++){
		int fr,to;
		fr=read();
		to=read();
		add_edge(fr,to);
		add_edge(to,fr);
	}
	tmp=1;
	dfs(1,-1);
//	for(int i=1;i<tmp;i++) printf("%d ",q[i]);
	for(int i=1;i<=tmp/2;i++) ans+=num[q[i]]-num[q[i+1]];
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