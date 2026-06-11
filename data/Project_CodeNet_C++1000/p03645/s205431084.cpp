#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define N 100005
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795


ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans;
}
vector<ll>v[10001];

void dfs(ll x,vector<bool>& vis)
{
vis[x]=true;
for(int j=0;j<v[x].size();j++)
  {
    ll t=v[x][j];
    dfs(t,vis);
  }

}

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

ll n,m;cin>>n>>m;
vector<bool>vis(n+1,false);
//vector<ll>v[n+1];
ll a,b;
set<ll>s1,s2;

for(int i=1;i<=m;i++)
{
  cin>>a>>b;
  if(a==1)s1.insert(b);
  else if(b==n)s2.insert(a);
}
for(auto x:s1)
{
  if(s2.find(x)!=s2.end())
  {
    cout<<"POSSIBLE"<<"\n";
    return 0;
  }
}

cout<<"IMPOSSIBLE"<<"\n";

}