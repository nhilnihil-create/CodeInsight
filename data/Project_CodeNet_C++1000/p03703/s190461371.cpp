#include <iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue> 
#include<cstring>
using namespace std;
#define ll long long
#define N 200005
struct cnm
{
	ll l,r;
	ll sum;
	void update(ll v)
	{
	    sum+=v*(r-l+1);
	}
};
struct ops
{
    ll pos,quan;
};
cnm tree[N<<2];
ops w[N<<2];
bool cmp(ops a,ops b)
{
	if(a.quan==b.quan)
	return a.pos<b.pos;
	return a.quan<b.quan;
}
#define mid (tree[x].l+tree[x].r)/2
#define lc x<<1
#define rc x<<1|1
void push_up(ll x)
{
	tree[x].sum=tree[lc].sum+tree[rc].sum; 
}
void built(ll l,ll r,ll x)
{
	tree[x].l=l;
	tree[x].r=r;
	tree[x].sum=0;
	if(l==r)
	return;
	built(l,mid,lc);
	built(mid+1,r,rc);
	push_up(x);
}
void update(ll x,ll pot)
{   
	if(tree[x].l==pot&&tree[x].r==pot)
	{
	    tree[x].sum++;
	    return;
	}
	if(pot<=mid)
	update(lc,pot);
	if(pot>mid)
	update(rc,pot);
	push_up(x);
}
ll he(ll l,ll r,ll x)
{  
	if(tree[x].l==l&&tree[x].r==r)
	return tree[x].sum;
	ll ans=0;
	push_up(x);
	if(r<=mid)
	return he(l,r,lc);
	else if(l>mid)
	return he(l,r,rc);
	else
	return he(mid+1,r,rc)+he(l,mid,lc);
}
int main()
{
           ll m,n;
           while(~scanf("%lld%lld",&m,&n))
           {
           	  ll a;
           	  built(1,m,1);
           	  for(int i=1;i<=m;i++)
           	  {
           	  	  scanf("%lld",&a);
           	  	  w[i].pos=i;
           	  	  a-=n;
           	  	  w[i].quan=w[i-1].quan+a;
			  }
			  sort(w+1,w+1+m,cmp);
			  ll ans=0;
			  for(int i=1;i<=m;i++)
			  {
			  	  update(1,w[i].pos);
			  	  if(w[i].quan>=0)
			  	  ans++;
			  	  if(w[i].pos==1)
			  	  continue;
			  	  ans+=he(1,w[i].pos-1,1);
			  }
			  printf("%lld\n",ans);
		   }
            return 0;
}
