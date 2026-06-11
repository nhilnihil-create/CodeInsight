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

vector<int> g[111111];
vector<int> ans[2];
int used[111111];

void dfs(int node,int k){
  used[node]=1;
  ans[k].pb(node);
  for(int i=0;i<g[node].size();i++){
    if(used[g[node][i]]==1)continue;
    dfs(g[node][i],k);
    break;
  }
}

int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  dfs(0,0);
  dfs(0,1);

  reverse(all(ans[0]));
  cout<<ans[0].size()+ans[1].size()-1<<endl;
  for(int i=0;i<ans[0].size();i++){
    if(i)cout<<" ";
    cout<<ans[0][i]+1;
  }
  for(int i=1;i<ans[1].size();i++){
    cout<<" "<<ans[1][i]+1;
  }
  cout<<endl;
  
  return 0;
}
