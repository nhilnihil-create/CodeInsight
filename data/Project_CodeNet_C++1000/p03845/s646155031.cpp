#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int xs,ys,n,m;
ll a[2003];
ll b[2003];
bool vis[1009][1009];
int ans[1000004];
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
           if(i==x)
           {
               sum+=y;
               continue;
           }
           sum+=a[i];
        }
        cout<<sum<<endl;
    }
}
