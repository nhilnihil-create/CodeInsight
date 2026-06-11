#include<cstdio>
int n,m,d[114514];
long long ans,A[233333];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	scanf("%d",d+i);
	for(int i=1;i<n;++i){
		int l=d[i],r=d[i+1];
		if(l>r)r+=m;
		ans+=r-l;
		++A[l+2],--A[r+1];
		A[r+1]-=r-l-1,A[r+2]+=r-l-1;
	}
	for(int i=1;i<=m*2;++i)A[i]+=A[i-1];
	for(int i=1;i<=m*2;++i)A[i]+=A[i-1];
	for(int i=1;i<=m;++i)A[i]+=A[i+m];
	long long mx=0;
	for(int i=1;i<=m;++i)if(mx<A[i])mx=A[i];
	printf("%lld\n",ans-mx);
	return 0;
}