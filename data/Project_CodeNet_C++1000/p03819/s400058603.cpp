#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e5+5,M=1e5+5;
struct node{
	int l,r,len;
}good[N];
int n,m,d,cnt,ans[M],tree[N];

inline bool cmp(node x,node y){
	return x.len<y.len;
}

inline int lowbit(int x){
	return x&(-x);
}

inline void add(int x,int w){
	while(x<=m){
		tree[x]+=w;
		x+=lowbit(x);
	}
}

inline int query(int x){
	int res=0;
	while(x){
		res+=tree[x];
		x-=lowbit(x);
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&good[i].l,&good[i].r);
		good[i].len=good[i].r-good[i].l+1;
	}
	sort(good+1,good+n+1,cmp);
	for(d=1;d<=m;d++){
		for(int i=cnt+1;i<=n;i++)
			if(good[i].len>d){
				cnt=i-1;
				break;
			}else{
				add(good[i].l,1);
				add(good[i].r+1,-1);
				cnt++;
			}
		int res=0;
		for(int i=1;i*d<=m;i++)	res+=query(i*d);
		ans[d]=n-cnt+res;
	}
	for(int i=1;i<=m;i++)	printf("%d\n",ans[i]);
	return 0;
}