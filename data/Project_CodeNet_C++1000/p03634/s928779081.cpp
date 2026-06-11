#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n;
  cin>>n;
  map<pair<ll,ll>,ll> path;
  vector<vector<ll>> connect(n);
  for (int i = 0; i < n-1; ++i)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    path[make_pair(a,b)]=c;
    path[make_pair(b,a)]=c;
    connect[a].push_back(b);
    connect[b].push_back(a);
  }
  ll q,k;
  cin>>q>>k;
  k--;
  vector<ll> dist(n);
  dist[k]=0;
  vector<bool> seen(n,false);
  seen[k]=true;
  queue<ll> next;
  next.push(k);
  while(!next.empty())
  {
    ll now=next.front();
    next.pop();
    for(const auto& e: connect[now]) 
    {
      if(seen[e]) continue;
      dist[e]=dist[now]+path[make_pair(now,e)];
      seen[e]=true;
      next.push(e);
    }
  }
  for (int i = 0; i < q; ++i)
  {
    ll x,y;
    cin>>x>>y;
    x--;y--;
    cout<<dist[x]+dist[y]<<endl;
  }
}