#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  string s; cin >> s;

  int n = s.size();
  map<char, int> mp;
  for(int i = 0; i < n; i++){
    mp[s[i]]++;
  }

  int ans = n * (n-1) / 2;
  for(char c = 'a'; c <= 'z'; c++){
    ans -= mp[c] * (mp[c]-1) / 2;
  }
  cout << ans + 1 << endl;

  return 0;
}
