// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define el putchar('\n')
#define ta putchar('	')
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
//	sprintf(str,"%s.out",s);
//	freopen(str,"w",stdout);
	#endif
}
inline int rd()
{
	static int x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=100010;
int n,d[N],head[N],tot=0;
ll a[N];
struct edge{int v,next;}e[N<<1];

inline void add(int u,int v){e[++tot]=edge{v,head[u]};head[u]=tot;++d[u];}

ll dfs(int u,int fat)
{
	if(d[u]==1)return a[u];
	ll sum=0,mx=0;
	fe(i,u){
		int v=e[i].v;if(v==fat)continue;
		ll hh=dfs(v,u);
		if(hh==-1)return -1;
		sum+=hh;mx=max(mx,hh);
	}
	if(sum<a[u])return -1;
	if(mx<sum-mx&&sum-a[u]>sum/2)return -1;
	if(mx>sum-mx&&sum-a[u]>sum-mx)return -1;
	return (ll)a[u]-(sum-a[u]);
}

int main()
{
	n=rd();fo(i,1,n)a[i]=rd();
	fo(i,2,n){
		int x=rd(),y=rd();
		add(x,y);add(y,x);
	}
	if(n==2)return puts(a[1]^a[2]?"NO":"YES"),0;
	int rt=0;
	fo(i,1,n)if(d[i]>1){rt=i;break;}
	puts(dfs(rt,0)==0?"YES":"NO");
	return 0;
}
