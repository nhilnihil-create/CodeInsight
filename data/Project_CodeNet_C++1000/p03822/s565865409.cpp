#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100005;
struct Edge{
	int to,next;
}e[MAXN];
int head[MAXN],n,cnt,rk[MAXN];
inline void insert(int u,int v)
{
	e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;
}
void dfs(int x)
{
	vector<int>t;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].to;
		dfs(v);
		t.push_back(rk[v]);
	}
	sort(t.begin(),t.end(),greater<int>());
	for(int i=0;i<t.size();++i)
		rk[x]=max(rk[x],i+1+t[i]);
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		int fa;
		scanf("%d",&fa);
		insert(fa,i);
	}
	dfs(1);
	cout<<rk[1]<<endl;
	return 0;
}
