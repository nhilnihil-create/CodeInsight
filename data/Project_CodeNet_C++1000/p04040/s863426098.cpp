#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define opt ios_base::sync_with_stdio(false); cin.tie(NULL);

ll f[200005],finv[200005];

ll p(ll x,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1) res=(res*x)%M;
        x=(x*x)%M;
        n/=2;
    }
    return res;
}

ll nCr(ll n,ll r)
{
    return (((f[n]*finv[r])%M)*finv[n-r])%M;
}

void freak__()
{
    ll h,w,a,b,sum=0,i;
    cin >> h >> w >> a >> b;
    vector<ll> v1,v2;
    f[0]=f[1]=1;
    for(i=2;i<200005;i++) f[i]=(f[i-1]*i)%M;
    finv[0]=finv[1]=1;
    for(i=2;i<200005;i++) finv[i]=(finv[i-1]*p(i,M-2))%M;
    for(i=1;i<=h-a;i++) v1.push_back(nCr(i+b-2,b-1));
    for(i=0;i<h-a;i++) v2.push_back(nCr(h-i+w-b-2,h-i-1));
    for(i=0;i<v1.size();i++) sum=(sum+(v1[i]*v2[i])%M)%M;
    cout << sum << "\n";
}

int main()
{
    opt;
    freak__();
    return 0;
}