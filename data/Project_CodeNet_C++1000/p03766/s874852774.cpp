#include <cstdio>

#define MAXN 1000010
#define mod 1000000007

unsigned long long n,f[MAXN],add;

int main()
{
    scanf("%d",&n);
    f[n]=n;
    f[n-1]=n*n%mod;
    for(int i=n-2;i>=1;--i)
    {
        add=(add+f[i+3])%mod;
        f[i]=(f[i+1]+(n-1)*(n-1)%mod)%mod;
        f[i]=(f[i]+add+i+1)%mod;
    }
    printf("%d\n",f[1]);
}