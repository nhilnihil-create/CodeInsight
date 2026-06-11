#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 300005
using namespace std;
struct P{
	int l,r;
}a[N];
struct trie{
	int w,l,r;
}t[N*25];
int n,m,cnt,root[N],pos[100005];
bool cmp(P a,P b){return a.l<b.l;}
void insert(int pre,int now,int l,int r,int x){
	t[now]=t[pre];
	t[now].w++;
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) t[now].l=++cnt,insert(t[pre].l,cnt,l,mid,x);
	else t[now].r=++cnt,insert(t[pre].r,cnt,mid+1,r,x);
}
int query(int k,int l,int r,int L,int R){
	if(L<=l&&R>=r) return t[k].w;
	int mid=l+r>>1,ans=0;
	if(L<=mid) ans+=query(t[k].l,l,mid,L,R);
	if(R>mid) ans+=query(t[k].r,mid+1,r,L,R);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		root[i]=++cnt;
		insert(root[i-1],cnt,1,m,a[i].r);
	}
	for(int i=1;i<=m;i++){
		pos[i]=pos[i-1];
		while(pos[i]<n&&a[pos[i]+1].l<=i) pos[i]++;
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int p=i;p<=m;p+=i){
			ans+=query(root[pos[p]],1,m,p,p+i-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}