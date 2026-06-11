#include <bits/stdc++.h>
#define rep(i,a,n) for (int i =a; i<n; i++) 
using namespace std;

int main() {
  int N; cin >> N;
  int s[N]; rep(i,0,N) cin >> s[i];
  bool dp[10001]; rep(i,0,10001) dp[i] =false;
  int ans =0;
  
  dp[0] = true;
  rep(i,0,N) {
    vector<int> tmp;
    rep(j,0,10001) if (dp[j]) tmp.push_back(j);
    for (auto a: tmp) dp[a+s[i]] = true;
  }
  
  for (int i =10000; i>0; i--) {
    if (dp[i] && i % 10 != 0) {
      ans = i; break;
    }
  }
  
  cout << ans << endl;
}