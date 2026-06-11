#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const int mo = 1e9 + 7;
typedef long long ll;
ll mx(ll x,ll y,ll z){return max(max(x,y),z);}
ll mn(ll x,ll y,ll z){return min(min(x,y),z);}
ll h,w;

void solve()
{
    ll x,y;
    cin>>x>>y;

    ll i,ans=min(x,y);
    if(x%3==0||y%3==0)ans=0;
    else
    {
        for(i=1;i<x;i++)ans=min(mx(i*y,(x-i)*(y/2),(x-i)*((y+1)/2))-mn(i*y,(x-i)*(y/2),(x-i)*((y+1)/2)),ans);
        swap(x,y);
        for(i=1;i<x;i++)ans=min(mx(i*y,(x-i)*(y/2),(x-i)*((y+1)/2))-mn(i*y,(x-i)*(y/2),(x-i)*((y+1)/2)),ans);

    }
    cout<<ans<<endl;
}
main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}