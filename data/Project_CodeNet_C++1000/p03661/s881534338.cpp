#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=2e5+10;
long long sum[maxn];
int n;

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            long long a;
            scanf("%lld",&a);
            if(i==1)
            {
                sum[1]=a;
                continue;
            }
            sum[i]=sum[i-1]+a;
        }

        long long minmum=abs(sum[n]-sum[1]-sum[1]);
        for(int i=1;i<n;i++)
        {
            minmum=min(minmum,abs(sum[n]-sum[i]-sum[i]));
        }
        printf("%lld",minmum);
    }
}
