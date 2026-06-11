#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  string s1, s2;
  cin >> s1 >> s2;
  
  vector<int> x;
  for(int i = 0; i < n; i++){
    if(s1.at(i) == s2.at(i)) x.push_back(1);
    else{
      x.push_back(2);
      i++;
    }
  }
  
  ll ans;
  if(x.at(0) == 1) ans = 3;
  else ans = 6;
  
  for(int i = 1; i < x.size(); i++){
    if(x.at(i - 1) == 1){
      ans *= 2;
    }
    else{
      if(x.at(i) == 2) ans *= 3;
    }
    ans %= MOD;
  }
  
  cout << ans << '\n';
}