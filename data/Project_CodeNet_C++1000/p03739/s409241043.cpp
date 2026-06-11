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
ll v[200009];
ll n;
ll solve(int x)
{
    ll ans=0,sum=x;
    for(int i=2;i<=n;i++)
    {
        ll u=v[i]+sum;
        if(sum<0)
        {
            if(u<=0)
            {
                ans+=abs(u)+1;
                u=1;
            }
        }else
        {
            if(u>=0)
            {
                ans+=u+1;
                u=-1;
            }
        }
        sum=u;
    }
    return ans;
}
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   //18:52
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v[i]=x;
    }
    if(v[1]==0)
    {
        cout<<min(solve(1),solve(-1))+1;
    }else
    {
        ll ans2,ans1=solve(v[1]);
        if(v[1]>0)
        {
            ans2=solve(-1)+v[1]+1;
        }else
        {
            ans2=solve(1)+abs(v[1])+1;
        }
        cout<<min(ans1,ans2);
    }

}
