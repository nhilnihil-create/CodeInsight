#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL N,X,ans;
int main()
{
	scanf("%lld%lld",&N,&X);
	ans+=N;N=N-X;
	while(N&&X)
	{
		if(X>N) swap(X,N);
		ans+=N/X*X*2;N%=X;
		if(!N) ans-=X;
	}
	printf("%lld\n",ans);
	return 0;
}