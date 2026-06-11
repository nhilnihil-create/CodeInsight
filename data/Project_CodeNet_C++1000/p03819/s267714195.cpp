#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 330000
using namespace std;
inline char gc(){
	static char now[1<<16],*T,*S;
	if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
	return *S++;
}
inline int read(){
	int x=0;char ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=gc();}
	return x;
}
struct node{
	int l,r;
}line[N];
inline bool cmp(node a,node b){return a.l<b.l;}
struct node1{
	int left,right,v;
}tree[N*20];
int num,n,m,root[N];
inline void insert1(int &x,int l,int r,int p){
	tree[++num]=tree[x];x=num;tree[x].v++;if (l==r) return;
	int mid=l+r>>1;if (p<=mid) insert1(tree[x].left,l,mid,p);else insert1(tree[x].right,mid+1,r,p);
}
inline int query(int rt1,int rt2,int l,int r,int l1,int r1){
	if (l1<=l&&r1>=r) return tree[rt2].v-tree[rt1].v;
	int mid=l+r>>1;int tmp=0;if (l1<=mid) tmp+=query(tree[rt1].left,tree[rt2].left,l,mid,l1,r1);
	if (r1>mid) tmp+=query(tree[rt1].right,tree[rt2].right,mid+1,r,l1,r1);return tmp;
}
int main(){
	//freopen("arc.in","r",stdin);
	n=read();m=read();
	for (int i=1;i<=n;++i) line[i].l=read(),line[i].r=read();
	sort(line+1,line+n+1,cmp);int tot=0;printf("%d\n",n);
	for (int i=1;i<=m;++i){root[i]=root[i-1];//printf("%d ",tree[root[i]].v);
	while(line[tot+1].l==i) insert1(root[i],1,m,line[tot+1].r),++tot;}//printf("%d\n",tree[root[i]].v);}
	for (int len=2;len<=m;++len){
		int j=len,tmp=0,now=m%len;now=m-now;
		for (;j<=m;j+=len) tmp+=query(root[j-len],root[j-1],1,m,j-len+1,j-1);
		if(now<m) tmp+=query(root[now],root[m],1,m,now+1,m);//printf("%d\n",tmp);
		printf("%d\n",n-tmp);
	}
	return 0;
}