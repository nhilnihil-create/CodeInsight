#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
const int inf=1e9+7;
const ll INF=1e18;
vector<vin> g;
vector<int> seen;
int n,m;
bool go(int x){
  if(x==0){
  
  for(auto v :g[x]){
     if (go(v)){
       return true;
     }
    
  }
    return false;
  }//if
  else {
    	for(auto v:g[x]){
            if(v==n-1) return true;
    
    	}
  }
  
  
  return false;
}

int main() {
  
  cin>>n>>m;
  
  /////////
  bool ans=true;
  g.resize(n);
  seen.assign(n,-1);
  vin a(m),b(m);
  rep(i,m) {
    
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  ans=go(0);
  
  if(ans) cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}