#include <cstdio>

typedef long long ll;
const ll mod = 1e9+7;

ll a[100005],b[100005],dy,ans;
int main(){
	int N, M; scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++) scanf("%lld",a+i);
	for(int i=0;i<M;i++) scanf("%lld",b+i);
	for(int i=1;i<N;i++){
		dy+=(a[i]-a[i-1])*(i)%mod*(N-i)%mod;
		dy%=mod;
	}
	for(int i=1;i<M;i++){
		ans+=(b[i]-b[i-1])*dy%mod*(i)%mod*(M-i)%mod;
		ans%=mod;
	}
	printf("%lld\n",ans);
}