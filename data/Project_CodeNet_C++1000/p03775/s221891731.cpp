#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int sx,sy,tx,ty;
//8c:1a:bf:89:66:b6
struct threeElements{
int _1st,_2nd,_3rd;
};
vector<vector<int>>adj(10);
ll solve(int a,int b)
{
    int f=0,s=0;
    while(a)
    {
        a/=10;
        f++;
    }
    while(b)
    {
        b/=10;
        s++;
    }
    return max(f,s);
}
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   //18:52
   ll n;
   cin>>n;
   ll ans=oo;
   for(ll i=1;i*i<=n;i++)
   {
       if(n%i==0)
       {
           ans=min(ans,solve(i,n/i));
       }
   }
   cout<<ans;
}
