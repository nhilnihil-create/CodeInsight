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
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
   }
   int ans=0,i=1;
   bool f=0;
   while(!vis[i])
   {
       ans++;
       if(a[i]==2)
        {
            f=1;
            break;
        }
       vis[i]=1;
       i=a[i];
   }
   if(f)
    cout<<ans;
   else
    cout<<-1;
}
