#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int sx,sy,tx,ty;
struct threeElements{
int _1st,_2nd,_3rd;
};
int n,m;
int color[14],a[100009];
bool vis[100009];
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   ll n,m;
   cin>>n>>m;
   ll ans=1,ans1=1;
   if(min(n,m)+1!=max(n,m)&&n!=m)
    return cout<<0,0;
   for(int i=1;i<=n;i++)
   {
       ans*=i;
       ans%=mod;
   }
   for(int i=1;i<=m;i++)
   {
       ans1*=i;
       ans1%=mod;
   }
   if(n==m)
   cout<<(ans*ans1*2)%mod;
   else
    cout<<(ans*ans1)%mod;

}
