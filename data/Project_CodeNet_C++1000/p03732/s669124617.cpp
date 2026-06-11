#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define N 100005
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795



ll binPowM(ll a,ll b, ll m)
{ 
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }
return ans%m;
}
ll f(ll x,ll y,ll a)
{
  return (a&x)*(a&y);
}

int main()
{  
  
ll n,w;cin>>n>>w;

vector<pair<ll,ll>>v;

map<ll,vector<ll>>m;

ll a,b;

for(int i=1;i<=n;i++)
{
  cin>>a>>b;
  m[a].pb(b);
}
vector<ll>store[4];
ll y=0;
while(y!=4)
{
    store[y].pb(0);
    y++;
}
y=0;
vector<ll>wt(4);
for(auto x:m)
{
  wt[y]=x.first;
  sort(x.second.begin(),x.second.end(),greater<>());
  ll temp=0,val=0;
 // store[y].pb(val);
  for(int i=0;i<x.second.size();i++)
  {
      temp+=x.first;
      if(temp>w)break;
      else 
        {
          val+=x.second[i];
          store[y].pb(val);
        }
  }
y++;
}

/*
for(int i=0;i<4;i++)
{
    for(int j=0;j<store[i].size();j++)cout<<store[i][j]<<" ";
    cout<<endl;
}
cout<<wt[0]<<wt[1]<<wt[2]<<wt[3]<<"\n";*/
ll ans=0;

for(int i=0;i<store[0].size();i++)
{
  for(int j=0;j<store[1].size();j++)
  {
    for(int k=0;k<store[2].size();k++)
    {
      for(int l=0;l<store[3].size();l++)
        {
          if(i*wt[0]+j*wt[1]+k*wt[2]+l*wt[3]<=w)
          {
            ans=max(ans,store[0][i]+store[1][j]+store[2][k]+store[3][l]);
          }
        }
    }
  }
}

cout<<ans<<"\n";


  return 0;

}



