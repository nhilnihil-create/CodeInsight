#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << ": " << x << endl
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;
const int MAXN=2e5+7;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
int arr[MAXN];

int n,a,b;
bool check(ll x)
{
    ll lazy=b*x;
    ll need=0;
    for(int i=0;i<n;++i)
    {
        if(arr[i]<=lazy) continue;
        else
        {
            need+=(arr[i]-lazy)/(a-b);
            if((arr[i]-lazy)%(a-b)) need++;
        }
    }
    return need<=x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a>>b;
    int mx=0;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int ans=INF;
    int l=1,r=1e9/b+1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid))
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
