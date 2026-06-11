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
int sum,n,m,visited[11];
int main()
{
   // freopen ("jumping.in","r",stdin);
   _IOS();
   //18:52
   ll n,m;
   cin>>n>>m;
   vector<pair<ll,ll>>v,v1;
   for(int i=0;i<n;i++)
   {
       int a,b;
       cin>>a>>b;
       v.push_back({a,b});
   }
   for(int i=0;i<m;i++)
   {
       int a,b;
       cin>>a>>b;
       v1.push_back({a,b});
   }
   for(int i=0;i<n;i++)
   {
       ll ans=oo,idx;
       for(int j=0;j<m;j++)
        {
            ll q=abs(v[i].first-v1[j].first)+abs(v[i].second-v1[j].second);
            if(q<ans)
            {
                ans=q;
                idx=j+1;
            }
        }
        cout<<idx<<endl;
   }
}
