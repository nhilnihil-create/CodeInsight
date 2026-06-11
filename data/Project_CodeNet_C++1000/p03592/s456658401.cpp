#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;


int main(){
  ll n,m,k; cin >> n >> m >> k; vl num(m*n+1,0);
  
  for(ll i=0; i <= n; i++){
    for(ll j=0; j <= m; j++){
      num[i*j+(n-i)*(m-j)] = 1;
    }
  }
  
  if(num[k] == 1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
      