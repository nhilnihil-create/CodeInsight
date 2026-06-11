#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,INF=1e18;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
ll findans(ll s,ll k)
{
    if(s==0)
    return 0;
    ll r=10,res=s;
    while(r<=s)
    {
        res=res+s%r+findans(s/r,s%r+k)+k;
        r=r*10;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll ans=0,s;
        cin>>s;
        cout<<findans(s,0)<<"\n";
    }
    return 0;
}