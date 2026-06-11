#include<bits/stdc++.h>
using std::swap;
typedef long long i64;
const i64 inf=1ll<<60;
const int N=110007;
int n,v0[N],ps[N],pp=0;
char op[N];
i64 ans=0,s1[N],s2[N];
i64 min(i64 a,i64 b){return a<b?a:b;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		if(i>1)scanf("%s",op+i);
		scanf("%d",v0+i);
		s1[i]=v0[i];
		if(op[i]=='-')v0[i]*=-1,ps[pp++]=i;
		ans+=v0[i];
		s2[i]=v0[i]+s2[i-1];
	}
	for(int i=n;i;--i)s1[i]+=s1[i+1];
	for(int i=1;i<pp;++i){
		int l=ps[i-1],r=ps[i];
		i64 v=s2[l]+s1[r]-(s2[r-1]-s2[l]);
		if(v>ans)ans=v;
	}
	printf("%lld\n",ans);
	return 0;
}