#include<algorithm>
#include<cstring>
#include<cstdio>
#define LL long long
#define Re register int
using namespace std;
const int N=2e5+3;
int n,t,A[N],L[N],R[N],Q[N];LL ans;
inline void in(Re &x){
    int f=0;x=0;char c=getchar();
    while(c<'0'||c>'9')f|=c=='-',c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
    x=f?-x:x;
}
int main(){
//	freopen("123.txt","r",stdin);
	in(n);
	for(Re i=1;i<=n;++i)in(A[i]);
	for(Re i=1;i<=n;++i){
		while(t&&A[Q[t]]>=A[i])--t;
		L[i]=Q[t]+1,Q[++t]=i;
	}
	Q[t=0]=n+1;
	for(Re i=n;i>=1;--i){
		while(t&&A[Q[t]]>=A[i])--t;
		R[i]=Q[t]-1,Q[++t]=i;
	}
	for(Re i=1;i<=n;++i)ans+=(LL)A[i]*(R[i]-i+1)*(i-L[i]+1);
	printf("%lld\n",ans);
}