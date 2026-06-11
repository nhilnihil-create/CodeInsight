#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll x[100000],y[100000];
int main()
{
    ll i,j,k;
    ll n,m;
    ll conx=(ll)0,cony=(ll)0;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%lld",&x[i]);
    for(i=0;i<m;i++)
        scanf("%lld",&y[i]);
    for(i=0;i<n-1;i++){
        conx=(conx+((x[i+1]-x[i])*((i+1)*(n-i-1))%mod)%mod)%mod;
    }
    //prllf("%d %d\n",conx,cony);
    for(i=0;i<m-1;i++){
        cony=(cony+((y[i+1]-y[i])*((i+1)*(m-i-1))%mod)%mod)%mod;
    }
    printf("%lld",(conx*cony)%mod);
}
