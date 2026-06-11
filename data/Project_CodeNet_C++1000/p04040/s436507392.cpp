#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,m,a,b;
const ll mod=1e9+7;


ll add(ll a, ll b)
{
    ll ret=a+b;
    if(ret>=mod)
        ret-=mod;
    return ret;
}

ll mul(ll a, ll b)
{
    return (a*b)%mod;
}

ll step(ll a, int st)
{
    ll r = 1;
    while(st)
    {
        if(st % 2)
            r = mul(r, a);
        a = mul(a, a);
        st /= 2;
    }
    return r;
}

ll div2(ll a, ll b)
{
    return mul(a,step(b,mod-2));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin>>n>>m>>a>>b;
    //cout<<mod;

    /*cout<<step(2,n);
    return 0;*/

    ll tek=1;
    ll tek2=1;
    for(ll i=n+m-b-2;i>m-b-1;i--)
        tek2=mul(tek2,i);
    for(ll i=n-1;i>0;i--)
        tek2=div2(tek2,i);
    //cout<<tek2<<endl;
    //return 0;
    //cout<<"*"<<tek2<<endl;
    ll sol=0;
    sol=add(sol,mul(tek,tek2));
    for(int i=2;i<=n-a;i++)
    {
        tek=mul(tek,i+b-2);
        tek=div2(tek,i-1);
        //cout<<"*"<<tek<<endl;
        tek2=div2(tek2,m-b+n-i);
        tek2=mul(tek2,n-i+1);
        sol=add(sol,mul(tek,tek2));
        //cout<<"*"<<tek2<<endl;
    }
    cout<<sol;

	return 0;
}
