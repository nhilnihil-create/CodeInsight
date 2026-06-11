#include<cstdio>
typedef long long LL;
const int N=1e5+8;
int A[N],op[N],n,nxt[N],nx;
LL ans,now,suf[N];char s[4];
int main(){
	scanf("%d%d",&n,A+1),ans=A[1];
	for(int i=2;i<=n;++i)scanf("%s%d",s,A+i),ans+=A[i]*((op[i]=*s=='-')?-1:1);
	for(int i=n;i;--i){
		suf[i]=suf[i+1]+A[i];
		if(op[i])nxt[i]=nx,nx=i;
	}
	now=A[1];
	for(int i=2;i<=n;++i){
		if(op[i]&&nxt[i]){
			LL nw=now-suf[i]+2*suf[nxt[i]];
			if(nw>ans)ans=nw;
		}
		now+=A[i]*(op[i]?-1:1);
	}
	printf("%lld\n",ans);
	return 0;
}