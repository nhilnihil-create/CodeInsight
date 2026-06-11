#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

const int N=3e5+5;
const int M=1e5+5;
const int T=1e7+5;
int n,m,st[M],en[M];
pair<int,int> p[N];

struct Chairman_Tree
{
	int seg_tot,rt[N];
	struct node
	{
		int lsn,rsn,cnt;
	};
	node seg[T];
	
	void update(int &rt,int las,int l,int r,int pos)
	{
		seg[rt=++seg_tot]=seg[las];
		++seg[rt].cnt;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) update(seg[rt].lsn,seg[las].lsn,l,mid,pos);
		else update(seg[rt].rsn,seg[las].rsn,mid+1,r,pos);
	}
	
	int query(int rt,int las,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return seg[rt].cnt-seg[las].cnt;
		int mid=(l+r)>>1;int ret=0;
		if(L<=mid) ret+=query(seg[rt].lsn,seg[las].lsn,l,mid,L,R);
		if(R>mid) ret+=query(seg[rt].rsn,seg[las].rsn,mid+1,r,L,R);
		return ret;
	}
};
Chairman_Tree SS;

void init()
{
	int i,now=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+n+1);
	
	for(i=1;i<=m;++i)
	{
		st[i]=now+1;
		while(p[now+1].first==i) ++now;
		en[i]=now;
	}
	
	for(i=1;i<=n;++i)
		SS.update(SS.rt[i],SS.rt[i-1],1,m,p[i].second);
}

int calc(int x,int y,int l,int r)
{
	return SS.query(SS.rt[en[y]],SS.rt[st[x]-1],1,m,l,r);
}

void work()
{
	int i,j,ans=0;
	for(i=1;i<=m;++i)
	{
		ans=0;
		for(j=i;j<=m;j+=i)
			ans+=calc(j-i+1,j,j,m);
		printf("%d\n",ans);
	}
}

int main()
{
	init();work();
	return 0;
}