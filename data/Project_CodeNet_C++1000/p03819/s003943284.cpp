#include<bits/stdc++.h>
#define N 600005
using namespace std;
int n,m,l,r,c[N];
struct node{int l,r,len;}a[N];
inline bool cmp(node aa,node bb){return aa.len<bb.len;}
inline int lowbit(int x){return x&-x;}
inline void add(int x,int y){for(int i=x;i<=m;i+=lowbit(i))c[i]+=y;}
inline int sum(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i];return ans;}
int main(){
	scanf("%d%d",&n,&m);int tot=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		a[i].l=l;a[i].r=r;
		a[i].len=r-l+1;
	}
	sort(a+1,a+n+1,cmp);int j=1;
	for (int i=1;i<=m;i++){
		for (;j<=n;j++){
			if (a[j].len>i) break;
			add(a[j].l,1);
			if (a[j].r+1<=m) add(a[j].r+1,-1);
		}
		int ans=n-j+1;
		for (int j=i;j<=m;j+=i) ans=ans+sum(j);
		printf("%d\n",ans);
	}
	return 0;
}