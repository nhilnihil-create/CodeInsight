#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll,ll>mp;
ll mod=1000000007;

void primefact(ll n)
{
    while(n%2==0)
    {
        mp[2]++;
        n/=2;
    }
    for(ll i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            mp[i]++;
            n/=i;
        }
    }
    if(n>2)
    {
        mp[n]++;
    }
    return;
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=2;i<=n;i++)
    {
        primefact(i);
    }
    ll prd=1;
    map<ll,ll>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        prd=(prd*((it->second)+1))%mod;
    }
    cout<<prd<<endl;
    return 0;
}