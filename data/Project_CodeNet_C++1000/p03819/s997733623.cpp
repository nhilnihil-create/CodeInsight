#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 300010
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int top;
struct node
{	int l,r,sum; node *lc,*rc;
	node(int _l=0,int _r=0):l(_l),r(_r){sum=0;lc=rc=NULL;}
}*rt[N],pool[7000000],*null;
inline node *newnode(int l,int r)
{	node *x=pool+ ++top;
	x->l=l; x->r=r; x->sum=0; x->lc=x->rc=null;
	return x;
}
node *build(int l,int r)
{	node *x=newnode(l,r);
	if(l==r) return x;
	int mid=(l+r)>>1;
	x->lc=build(l,mid); x->rc=build(mid+1,r);
	return x;
}
struct Q{int l,r;}q[N];
node *ins(node *la,int pos)
{	node *x=newnode(la->l,la->r); x->lc=la->lc; x->rc=la->rc; x->sum=la->sum+1;
	if(x->l==x->r) return x;
	int mid=(x->l+x->r)>>1;
	if(pos<=mid) x->lc=ins(la->lc,pos);
	else x->rc=ins(la->rc,pos);
	return x;
}
int query(node *x,node *y,int l,int r)
{	if(x->l==l&&x->r==r) return x->sum-y->sum;
	int mid=(x->l+x->r)>>1;
	if(r<=mid) return query(x->lc,y->lc,l,r);
	else if(l>mid) return query(x->rc,y->rc,l,r);
	else return query(x->lc,y->lc,l,mid)+query(x->rc,y->rc,mid+1,r);
}
inline bool cmp(Q x,Q y){return x.l<y.l;}
int main()
{	int n,m; cin>>n>>m; rt[0]=build(1,m);
	null=pool; null->lc=null->rc=null; null->l=null->r=null->sum=0;
	for(rint i=1;i<=n;i++) scanf("%d%d",&q[i].l,&q[i].r);
	sort(q+1,q+n+1,cmp);
	for(rint i=1,j=1;i<=m;i++)
	{	rt[i]=rt[i-1];
		for(;j<=n&&q[j].l==i;j++) rt[i]=ins(rt[i],q[j].r);
	}
	printf("%d\n",n);
	for(rint i=2;i<=m;i++)
	{	int sum=n;
		for(rint j=0;j<m;j+=i) sum-=query(rt[min(m,j+i-1)],rt[j],j+1,min(m,j+i-1));
		printf("%d\n",sum);
	}
	return 0;
}
