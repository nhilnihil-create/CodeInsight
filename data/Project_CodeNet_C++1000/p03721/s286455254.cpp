#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;



  
int main() {
  ll n,k;
  cin >>n>>k;
  vector<ll> v(100001,0);
  rep(i,n){
    int a,b;
    cin >>a>>b;
    v[a] += b;
  }
  ll sum = 0;
  rep(i,10000000001){
    sum += v[i];
    if(sum>=k){
      cout << i << endl;
      break;
        
    }
  }
    
    
}