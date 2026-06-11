#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)
            res=res*a;
        n=n/2;
        a=a*a;
    }
    return res;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    cout<<k*power(k-1,n-1)<<"\n";
}
