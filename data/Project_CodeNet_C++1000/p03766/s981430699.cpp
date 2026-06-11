#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define mod 1000000007
int n,f[MAXN],add;
int main()
{
    scanf("%d",&n);
    f[n]=n;
    f[n-1]=(long long)n*n%mod;
    for(int i=n-2;i>=1;--i)
    {
        add=(add+f[i+3])%mod;
        f[i]=f[i+1];
        f[i]=(f[i]+(long long)(n-1)*(n-1)%mod)%mod;
        f[i]=(f[i]+add)%mod;
        f[i]=(f[i]+i+1)%mod;
    }
    printf("%d\n",f[1]);
}