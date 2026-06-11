#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
map< ll, int > prime_factor(ll n) {
  map< ll, int > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

map<ll, int> merge(map<ll,int> m1, map<ll, int> m2){
  if(m1.size() > m2.size()){
    return merge(m2, m1);
  }
  for(auto m : m1){
    if(m2.count(m.first) == 0){
      m2[m.first] = m.second;
    } else {
      m2[m.first] += m.second;
    }
  }
  return m2;
}

int main(){
  ll N;
  int MOD = 1000000000 + 7;
  cin >> N;
  map<ll,int> m = prime_factor(2);
  for(int i = 3; i <= N; i++){
    map<ll,int> m2 = prime_factor(i);
    m = merge(m, m2);
  }
  
  ll ans = 1;
  for(auto x: m){
    cerr << x.first << " " << x.second << endl;
    ans =  ans * (x.second + 1);
    ans = ans % MOD;
  }
  if( N == 1){
    cout << 1 << endl;
  } else if(N == 2){
    cout << 2 << endl;
  } else {
    cout << ans << endl;
  }

}