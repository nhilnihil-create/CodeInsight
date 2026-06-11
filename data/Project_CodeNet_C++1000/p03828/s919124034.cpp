#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ara[10000];
ll mod=1000000007;
void prime(ll n)
{
    while(n%2==0)
    {
        ara[2]++;
        n/=2;
    }
    for(ll i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            ara[i]++;
            n/=i;
        }
    }
    if(n>2)
    {
        ara[n]++;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    queue<ll>q,v;
    for(ll i=2;i<=n;i++)
    {
        prime(i);
    }
    ll prd=1;
    prd*=(ara[2]+1);
    for(ll i=3;i<=n;i+=2)
    {
        prd=(prd*(ara[i]+1))%mod;
    }
    cout<<prd<<endl;
    return 0;

}