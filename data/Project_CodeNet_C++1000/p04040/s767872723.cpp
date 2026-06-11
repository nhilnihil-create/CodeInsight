 /***     
 * When I wrote this
 * only God & I understood
 * what I was doing
 * Now, God only knows 
 /***/ 
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include <iomanip>
#include<map>
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<=n;i++)/*i为循环变量，a为初始值，n为界限值，递增*/
#define per(i,a,n) for (int i=a;i>=n;i--)/*i为循环变量， a为初始值，n为界限值，递减*/
const int mod = 1e9+7;
using namespace std;
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
//fixed<< setprecision(2)
ll p[200005];
ll powmod(ll x,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans=(ans*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }return ans;
}
ll ccc(ll n,ll m)
{
    ll x=p[n];
    ll y=(p[m]*p[n-m])%mod;
    return (x*powmod(y,mod-2))%mod;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    p[0]=1;
    for(int i=1;i<200005;i++)p[i]=(p[i-1]*i)%mod;
    ll n,m,a,b;
    while(cin>>n>>m>>a>>b)
    {
       ll ans=0;
       for(int i=b+1;i<=m;i++)
       {
           ll tmp=(ccc(i-1+n-a-1,n-a-1)*ccc(m-i+a-1,m-i))%mod;
           ans=(ans+tmp)%mod;
       }cout<<ans<<'\n';
    }
}