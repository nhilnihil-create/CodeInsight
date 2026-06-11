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
    int k,s,ans=0;
    cin>>k>>s;
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=k;j++)
        {
            int q=s-(i+j);
            if(q>=0&&q<=k)
                ans++;
        }
    }
    cout<<ans;
}
