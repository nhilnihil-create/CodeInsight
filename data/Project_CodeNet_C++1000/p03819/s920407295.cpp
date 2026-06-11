#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 3e+5+5;

int n,m;
struct edge{
	int x,nxt;
}e[N];
int h[N],et;
struct node{
	int l,r,tot;
}tree[N*18];
int rt[N],tot;

void inse(int x,int y){e[++et].x=y;e[et].nxt=h[x];h[x]=et;}

void add(int &now,int qf,int l,int r,int x){
	tree[now=++tot]=tree[qf];
	tree[now].tot++;
	if (l==r)return;
	int mid=(l+r)/2;
	if (x<=mid)add(tree[now].l,tree[qf].l,l,mid,x);
	else add(tree[now].r,tree[qf].r,mid+1,r,x);
}

int gettot(int now,int qf,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].tot-tree[qf].tot;
	int mid=(l+r)/2,cnt=0;
	if (x<=mid)cnt=gettot(tree[now].l,tree[qf].l,l,mid,x,y);
	if (y>mid)cnt+=gettot(tree[now].r,tree[qf].r,mid+1,r,x,y);
	return cnt;
}

int main(){
	n=get();m=get();
	fo(i,1,n){int l=get(),r=get();inse(r,l);}
	fo(i,1,m){
		rt[i]=rt[i-1];
		for(int p=h[i];p;p=e[p].nxt)add(rt[i],rt[i],1,m,e[p].x);
	}
	printf("%d\n",n);
	fo(i,2,m){
		int ans=n;
		fo(j,0,m/i)
			ans=ans-gettot(rt[min(m,(j+1)*i-1)],rt[j*i],1,m,j*i+1,min(m,(j+1)*i-1));
		printf("%d\n",ans);
	}
	return 0;
}