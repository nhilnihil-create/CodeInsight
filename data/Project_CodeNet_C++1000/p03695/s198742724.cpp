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
int color[14],a[1000];
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
    int a[1000];
    cin>>n;
    ll mn=0,mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        int q=a[i]/400;
        color[q]++;
    }
    for(int i=0;i<8;i++)
    {
        if(color[i]) mn++;
    }
    for(int i=8;i<13;i++)
        if(color[i]) mx+=color[i];
    if(mn==0)
    {
        cout<<1<<" "<<mx;
        return 0;
    }
    cout<<mn<<" ";
        cout<<mn+mx;
}
