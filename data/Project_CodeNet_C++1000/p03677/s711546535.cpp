#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 1000000
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
struct L{ll x,y;}; int p[N];
struct node{int l,r;L s,tag;}a[N];
void build(int l,int r,int o)
{	a[o].l=l; a[o].r=r;
	if(l==r) return;
	int mid=(a[o].l+a[o].r)>>1;
	build(l,mid,o+o); build(mid+1,r,o+o+1);
}
void add(int l,int r,L g,int o)
{//	if(o==1) cerr<<"!!!"<<l<<" "<<r<<" "<<g.x<<" "<<g.y<<endl;
	if(l>r) return;
	if(a[o].l==l&&a[o].r==r){a[o].tag.x+=g.x;a[o].tag.y+=g.y;return;}
	int mid=(a[o].l+a[o].r)>>1;
	if(r<=mid) add(l,r,g,o+o);
	else if(l>mid) add(l,r,g,o+o+1);
	else add(l,mid,g,o+o),add(mid+1,r,L{g.x+g.y*(mid-l+1),g.y},o+o+1);
}
inline void down(int o)
{	a[o].s.x+=a[o].tag.x; a[o].s.y+=a[o].tag.y;
	if(a[o].l!=a[o].r) a[o+o].tag.x+=a[o].tag.x,a[o+o].tag.y+=a[o].tag.y,
	a[o+o+1].tag.x+=a[o].tag.x+a[o].tag.y*(a[o+o].r-a[o+o].l+1),
	a[o+o+1].tag.y+=a[o].tag.y;
	a[o].tag=L{0,0};
}
ll query(int pos,int o)
{	down(o);
	if(a[o].l==a[o].r) return a[o].s.x;
	int mid=(a[o].l+a[o].r)>>1;
	if(pos<=mid) return query(pos,o+o); else return query(pos,o+o+1);
}
#define dis(x,y) ((y-1)-(x-1)+m)%m
int main()
{	int n,m; ll ans=1e18; cin>>n>>m; build(1,m,1);
	for(rint i=1;i<=n;i++) scanf("%d",&p[i]);
	for(rint i=1;i<n;i++)
	{	if(p[i+1]>p[i])
		add(1,p[i],L{dis(p[i],p[i+1]),0},1),add(p[i+1]+1,m,L{dis(p[i],p[i+1]),0},1),
		add(p[i]+1,p[i+1],L{dis(p[i],p[i+1]),-1},1);
		else
		add(p[i]+1,m,L{dis(p[i],p[i+1]),-1},1),add(1,p[i+1],L{dis(1,p[i+1])+1,-1},1),
		add(p[i+1]+1,p[i],L{dis(p[i],p[i+1]),0},1);
	}
	for(rint i=1;i<=m;i++) ans=min(ans,query(i,1));
	cout<<ans;
	return 0;
}
