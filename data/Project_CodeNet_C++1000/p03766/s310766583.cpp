#include<bits/stdc++.h>
#define reg register
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
ll n,f[1000005],s;
int main()
{
    cin>>n;
    f[n]=n;
    f[n-1]=n*n%1000000007;
    for(reg int i=n-2;i>=1;i--)
    {
        s=(s+f[i+3])%1000000007;
        f[i]=(f[i+1]+(n-1)*(n-1)%1000000007+s+i+1)%1000000007;
    }
    printf("%d\n",f[1]);
}