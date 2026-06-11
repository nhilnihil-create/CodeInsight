#include <bits/stdc++.h>
using namespace std;
#define N 300010
int n,m,tot=0,root[N],ans[N];
struct node{int x,y;}a[N];
struct seg{int l,r,x;}t[N*100];
inline char gc(){
	static char *S,*T,buf[1<<16];
	if(T==S){T=(S=buf)+fread(buf,1,1<<16,stdin);if(T==S) return EOF;}
	return *S++;
}
inline int read(){
	int x=0,f=1;char ch=gc();
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=gc();}
	while('0'<=ch && ch<='9') x=x*10+ch-'0',ch=gc();
	return x*f;
}
inline bool cmp(node x,node y){
	return x.x<y.x;
}
inline void ins(int &v,int l,int r,int x){
	t[++tot]=t[v];v=tot;t[v].x++;
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) ins(t[v].l,l,mid,x);
	else ins(t[v].r,mid+1,r,x);
}
inline int query(int v1,int v2,int l,int r,int x,int y){
	if(x<=l && r<=y) return t[v2].x-t[v1].x;
	int mid=l+r>>1,s=0;
	if(x<=mid) s+=query(t[v1].l,t[v2].l,l,mid,x,y);
	if(mid<y) s+=query(t[v1].r,t[v2].r,mid+1,r,x,y);
	return s;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		a[i].x=read(),a[i].y=read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1,j=1;i<=m;++i){
		root[i]=root[i-1];
		while(j<=n && a[j].x==i) ins(root[i],1,m,a[j].y),++j;
	}
//	printf("%d\n",tot); 
//	for(int i=1;i<=m;++i) printf("%d ",root[i]);puts("");
//	for(int i=1;i<=tot;++i) printf("%d %d %d %d\n",i,t[i].l,t[i].r,t[i].x);
	printf("%d\n",n);
	for(int i=2;i<=m;++i){
		for(int j=i;j<=m;j+=i){
			ans[i]+=query(root[j-i],root[j],1,m,j,m);
		}
		printf("%d\n",ans[i]);
	}
	return 0;
}