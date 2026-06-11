#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int n,m,q;
int clr[111111];
int lst[111111];
vector<int> g[111111];

void dfs(int v,int d,int c){
  if(!clr[v])clr[v]=c;
  if(lst[v]>=d)return;
  lst[v]=d;
  if(d==0)return;
  for(int u:g[v])dfs(u,d-1,c);
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;++i){
    int a,b;
    cin>>a>>b;
    --a,--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  
  cin>>q;
  vector<tuple<int,int,int> > vv;
  for(int i=0;i<q;++i){
    int v,d,c;
    cin>>v>>d>>c;
    v--;
    vv.pb(make_tuple(v,d,c));
  }
  
  reverse(all(vv));
  for(int i=0;i<q;++i){
    int v,d,c;
    tie(v,d,c)=vv[i];
    dfs(v,d,c);
  }

  for(int i=0;i<n;++i){
    cout<<clr[i]<<endl;
  }
  
  return 0;
}
