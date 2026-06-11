#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*
ll dx[8]={-1,-1,-1,0,0,1,1,1};
ll dy[8]={-1,0,1,-1,1,-1,0,1};
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
*/
int main()
{
     ll n,m,a,b;
     cin>>n>>m;
     vector<pair<ll,ll> > v1,v2;
     for(int i=0;i<n;i++)
     {
         cin>>a>>b;
         v1.pb({a,b});
     }
     for(int i=0;i<m;i++)
     {
         cin>>a>>b;
         v2.pb({a,b});
     }
     ll pos;
     vector<ll> vec;
     for(int i=0;i<v1.size();i++)
     {
         ll mx=INT_MAX;
         for(int j=0;j<v2.size();j++)
         {
             ll dis=abs(v1[i].f-v2[j].f)+abs(v1[i].s-v2[j].s);
             //cout<<mx<<endl;
             if(dis<mx)
             {
                 pos=j+1;
                 mx=dis;
             }
         }
         vec.pb(pos);
     }
     for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<endl;
}
