#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int xs,ys,n,m;
ll a[200003];
ll b[2003];
bool vis[1009][1009];
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
    cin>>n;
    bool f=0;
    int nz=0;
    set<int>s;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x=(a[i]+n-1)/2,y=n-1-x;
        if(x+y!=n-1)
            f=1;
        if(a[i]==0)
            nz++;
        if(a[i]!=0)
            s.insert(a[i]);
        mp[a[i]]++;
        if(mp[a[i]]>2)
            f=1;
    }
    if(f||nz>1)
        return cout<<0,0;
    ll ans=1;
    for(int i=1;i<=s.size();i++)
    {
        ans*=2;
        ans%=mod;
    }
    cout<<ans;

}
