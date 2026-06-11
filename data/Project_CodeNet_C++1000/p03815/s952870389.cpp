#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int sx,sy,tx,ty;
ll a[3009][3009];
ll b[200003];
ll n,m;
bool vis[1009][1009];
struct threeElements{
int _1st,_2nd,_3rd;
};
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   //18:17
    ll x;
    cin>>x;
    int q=x%11;
    x=x*1.0/11;
    x*=2;
    if(q==0)
        return cout<<x,0;
    if(q<=6)
        x++;
    else
        x+=2;
    cout<<x;
}
