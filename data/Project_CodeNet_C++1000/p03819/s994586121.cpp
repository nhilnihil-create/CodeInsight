#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int N=300005;

struct ST{
	int l,r,f;
}t[N<<2];
struct node{
	int l,r,d;
	node(){}
	node(int l,int r,int d):l(l),r(r),d(d){}
}a[N];
int n,m,l,r,d,ans;

bool cmp(node a,node b){
	return a.d<b.d;
}

void build(int k,int l,int r){
	t[k].l=l; t[k].r=r;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}

void add(int k,int f){
	t[k].f+=f;
}

void pushdown(int k){
	if (t[k].f){
		add(k<<1,t[k].f);
		add(k<<1|1,t[k].f);
		t[k].f=0;
	}
}

void modify(int k,int L,int R){
	if (L<=t[k].l&&t[k].r<=R){
		add(k,1);
		return;
	}
	pushdown(k);
	int mid=(t[k].l+t[k].r)>>1;
	if (L<=mid) modify(k<<1,L,R);
	if (R>mid) modify(k<<1|1,L,R);
}

int query(int k,int p){
	if (t[k].l==t[k].r) return t[k].f;
	pushdown(k);
	int mid=(t[k].l+t[k].r)>>1;
	if (p<=mid) return query(k<<1,p);
	else return query(k<<1|1,p);
}

int main(){
	int i,p;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		a[i]=node(l,r,r-l+1);
	}
	sort(a+1,a+1+n,cmp);
	build(1,1,m);
	p=1;
	for (d=1;d<=m;d++){
		for (;p<=n&&a[p].d<d;p++) modify(1,a[p].l,a[p].r);
		ans=n-p+1;
		for (i=d;i<=m;i+=d) ans+=query(1,i);
		printf("%d\n",ans);
	}
	return 0;
}