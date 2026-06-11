#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mod 1000000007
#define maxn 1000010
using namespace std;
typedef long long ll;
ll n;
ll f[maxn];
int main(){
    scanf("%lld",&n);
    f[0]=1;
    f[1]=n;
    f[2]=n*n;
    ll now=0;
    for(int i=3;i<=n;i++)
    {
        f[i]=f[i-1];
        f[i]=(f[i]+(n-1)*(n-1)%mod)%mod;
        f[i]=(f[i]+now)%mod;
        f[i]=(f[i]+(ll)(n-i+2))%mod;
        now=(now+f[i-2])%mod;
    }
    printf("%lld\n",f[n]);
    return 0;
}