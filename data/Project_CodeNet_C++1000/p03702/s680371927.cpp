#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

using namespace std;

ll n,a,b;
ll h[100001];

bool f(ll x)
{
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
        ll val=(ceil)(((ld)h[i]-b*x)/(a-b));
        if(val>0) cnt+=val;
    }
    if(cnt<=x) return true;
    return false;
}

int main()
{
    IOS
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    ll st=1,en=1e9,mid,ans=en;
    while(st<=en)
    {
        mid=st+(en-st)/2;
        if(f(mid))
        {
            ans=min(ans,mid);
            en=mid-1;
        }
        else st=mid+1;
    }
    cout<<ans<<endl;
    return 0;

}
