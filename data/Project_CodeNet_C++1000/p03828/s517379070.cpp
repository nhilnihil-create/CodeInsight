#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pb  push_back
#define  F   first
#define  S   second
ll N=1e3+3,M=1e9+7;
vector<ll>v;
ll a[1003],c[1003];
int main()
{
    ft
    ll t,i,j,n,m,l,r;
    for(i=3;i<=(N/i);i++)
    {
        for(j=i*i;j<=N;j+=2*i)
        {
            a[j]=1;
        }
    }
    v.pb(2);
    for(i=3;i<N;i+=2)
    {
        if(a[i]==0)
        {
            v.pb(i);
        }
    }
    ll sz=v.size();
    cin>>n;
    for(i=2;i<=n;i++)
    {
        m=i;
        for(j=0;j<sz && v[j]<=(m/v[j]);j++)
        {
            l=v[j];
            while(m%l==0)
            {
                m/=l;
                c[l]++;
            }
        }
        if(m>1)
        {
            c[m]++;
        }
    }
    r=1;
    for(i=0;i<sz;i++)
    {
        r=(r*(c[v[i]]+1ll))%M;
    }
    cout<<r<<"\n";
    return 0;
}

