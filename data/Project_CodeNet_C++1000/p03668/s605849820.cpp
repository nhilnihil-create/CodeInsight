#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

ll n;
mat G(n);
vec d(n);
ll dfs(ll a){
  if(a!=0 && G[a].size()==1)return 0;
  ll g=0;
  for(ll i=0;i<G[a].size();i++){
    if(d[G[a][i]]<=d[a])continue;
    g^=((dfs(G[a][i]))+1);
  }
  return g;
}

int main(){

  cin >> n;
  G=mat(n);
  for(ll i=0;i<n-1;i++){
    ll a,b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }

  queue<ll> que;
  que.push(0);
  d=vec(n,-1);
  d[0]=0;

  //cout << 5 << endl;

  while(!que.empty()){
    ll v=que.front();
    que.pop();

    for(ll i=0;i<G[v].size();i++){
      if(d[G[v][i]]==-1){
        d[G[v][i]]=d[v]+1;
        que.push(G[v][i]);
      }
    }
  }

  //cout << 5 << endl;/

  //cout << dfs(0) << endl;

  if(dfs(0)==0)cout << "Bob" << endl;
  else cout << "Alice" << endl;


}