#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int,int> pii;
#define fi first
#define se second
#define ml(a,b) make_pair(a,b)
const int _ = 200002 , __ = _<<1;
struct edges
{
	int to[__],ne[__],he[_],ecnt;
	edges(){memset(he,0,sizeof(he)),ecnt=1;}
	void adde(int a,int b){to[++ecnt]=b,ne[ecnt]=he[a],he[a]=ecnt;}
	void addde(int a,int b){adde(a,b),adde(b,a);}
}e1,e2;
int n,m1,m2,ans[_],bel[_],csz[_],ccnt;
void bfs(int s,edges &e,int col)
{
	csz[col]=0;
	register int i,a,b;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		a=q.front(),q.pop();
		if(bel[a])continue;
		bel[a]=col,csz[col]++;
		for(i=e.he[a];i;i=e.ne[i])
		{
			b=e.to[i];
			if(bel[b])continue;
			q.push(b);
		}
	}
}
map<pii,int> cnt;
int main()
{
	register int i,a,b;
	register pii x;
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=m1;i++)scanf("%d%d",&a,&b),e1.addde(a,b);
	for(i=1;i<=m2;i++)scanf("%d%d",&a,&b),e2.addde(a,b);
	ccnt=0,memset(bel,0,sizeof(bel));
	for(i=1;i<=n;i++)if(!bel[i])bfs(i,e1,++ccnt);
	for(i=1;i<=n;i++)ans[i]=bel[i];
	ccnt=0,memset(bel,0,sizeof(bel));
	for(i=1;i<=n;i++)if(!bel[i])bfs(i,e2,++ccnt);
	cnt.clear();
	for(i=1;i<=n;i++)
	{
		x=ml(ans[i],bel[i]);
		if(cnt.count(x))cnt[x]++;
		else cnt[x]=1;
	}
	for(i=1;i<=n;i++)printf("%d ",cnt[ml(ans[i],bel[i])]);
	puts("");
	return 0;
}
