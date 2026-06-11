#include <cstdio>
typedef long long ll;

int n,f[1000005];
const int p=1000000007;

int main()
{
    scanf("%d",&n),f[n]=n,f[n-1]=(ll)n*n%p;
    for(int i=n-2,s=0;i>=1;--i)s=(s+f[i+3])%p,f[i]=(s+ll(n-1)*(n-1)+f[i+1]+i+1)%p;
    return printf("%d\n",f[1]),0;
}