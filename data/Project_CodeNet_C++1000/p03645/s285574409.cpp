#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main(){
  ll n, m;
  cin >> n >> m;
  vector<ll> s(n, 0);
  vector<ll> g(n, 0);
  
  
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b;
    if(a==1){
      s[b-1] = 1;
    }else if(b==n){
      g[a-1] = 1;
    }
  }

  bool flag = false;
  
  for(int i=1; i<n; i++){
    if(s[i]==1 && g[i]==1) flag=true;
  }
  
  
  if(flag) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  
  return 0;
}