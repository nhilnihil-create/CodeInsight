#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  string s; cin >> s;

  int n = s.size();
  vector<int> c(26, 0);
  for(int i = 0; i < n; i++){
    c[s[i]-'a']++;
  }

  int sum = n * (n-1) / 2;
  for(int i = 0; i < 26; i++){
    sum -= max(0LL, c[i] * (c[i]-1) / 2);
  }
  cout << sum+1 << endl;

  return 0;
}
