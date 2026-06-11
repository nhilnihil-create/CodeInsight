#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=3e5+5;
int n,m,L[MN],R[MN],id[MN];
int d[MN];
#define lowbit(x) (x&-x)
inline void update(int x,int v){while(x<=m)d[x]+=v,x+=lowbit(x);}
inline void update(int l,int r,int v){update(l,v);update(r+1,-v);}
inline int query(int x){reg int res=0;while(x)res+=d[x],x-=lowbit(x);return res;}
int main(){
	scanf("%d%d",&n,&m);
	for(reg int i=1;i<=n;i++)scanf("%d%d",L+i,R+i),id[i]=i;
	sort(id+1,id+1+n,[](int a,int b){
		return R[a]-L[a]<R[b]-L[b];
	});
	reg int cur=1,Ans;
	for(reg int d=1;d<=m;d++){
		while(cur<=n&&R[id[cur]]-L[id[cur]]+1<d)
			update(L[id[cur]],R[id[cur]],1),cur++;
		Ans=n-cur+1;
		for(reg int i=d;i<=m;i+=d)Ans+=query(i);
		printf("%d\n",Ans);
	}
	return 0;
}