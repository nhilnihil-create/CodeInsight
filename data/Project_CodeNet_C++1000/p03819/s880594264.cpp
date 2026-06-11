#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define N 100010
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,m,rt[N],owo=0;
struct node{
	int lc,rc,x;
}tree[N*3*20];
struct point{
	int x,y;
}a[N*3];
inline bool cmp(point x,point y){return x.x<y.x;}
inline void add(int &p,int l,int r,int x){
	tree[++owo]=tree[p];p=owo;tree[p].x++;
	if(l==r) return;int mid=l+r>>1;
	if(x<=mid) add(tree[p].lc,l,mid,x);
	else add(tree[p].rc,mid+1,r,x);
}
inline int ask(int p1,int p2,int l,int r,int x,int y){
	if(x<=l&&r<=y) return tree[p2].x-tree[p1].x;
	int mid=l+r>>1,res=0;
	if(x<=mid) res+=ask(tree[p1].lc,tree[p2].lc,l,mid,x,y);
	if(y>mid) res+=ask(tree[p1].rc,tree[p2].rc,mid+1,r,x,y);
	return res;
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	sort(a+1,a+n+1,cmp);int now=1;
	for(int i=1;i<=m;++i){
		rt[i]=rt[i-1];
		while(now<=n&&a[now].x==i){
			add(rt[i],1,m,a[now].y);++now;
		}
	}printf("%d\n",n);
	for(int i=2;i<=m;++i){
		int ans=n,x=i;
		for(x=i;x<=m;x+=i) ans-=ask(rt[x-i],rt[x-1],1,m,x-i+1,x-1);
		if(x-i+1<=m) ans-=ask(rt[x-i],rt[m],1,m,x-i+1,m);printf("%d\n",ans);
	}return 0;
}