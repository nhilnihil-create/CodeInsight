#include <cstdio>
using namespace std;
typedef long long LL;
const int maxn=100001;
const LL mod=1e9+7;

int n,x[maxn];
LL ans;
int cnt;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	
	cnt=0;ans=1;
	for(int i=1;i<=n;i++)
	{
		cnt++;
		if (x[i]<2*cnt-1)
	    {
	    	ans=(ans*cnt)%mod;
	    	cnt--;
	    }
    }
	    
	for(int i=2;i<=cnt;i++)
	    ans=(ans*i)%mod;
	printf("%I64d\n",ans);
	return 0;
}