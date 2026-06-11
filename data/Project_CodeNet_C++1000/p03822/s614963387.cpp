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

int dfs(int nd=1){
  

 
  
  vector<int> w;
  for(int i=0;i<g[nd].size();i++){
    w.pb(dfs(g[nd][i]));
  }
  //cout<<endl;
  //dbg(nd); 
  sort(all(w));
  int n=w.size();
  int ma=0;
  for(int i=0;i<n;i++){
    //dbg(w[i]);
    ma=max(ma,(n-i)+w[i]);
  }

  return ma;
}

int main(){
  int n;
  cin>>n;
  for(int i=2;i<=n;i++){
    int a;
    cin>>a;
    g[a].pb(i);
  }

  cout<<dfs()<<endl;
  
  return 0;
}
