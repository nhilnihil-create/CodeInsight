#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,f[1000010],add;

int main()
{
    scanf("%d",&n);
    f[n]=n;
    f[n-1]=(ll)n*n%1000000007;
    for(int i=n-2;i>=1;--i)
    {
        add=(add+f[i+3])%1000000007;
        f[i]=f[i+1];
        f[i]=(f[i]+(ll)(n-1)*(n-1)%1000000007)%1000000007;
        f[i]=(f[i]+add)%1000000007;
        f[i]=(f[i]+i+1)%1000000007;
    }
    printf("%d\n",f[1]);
    return 0;
}