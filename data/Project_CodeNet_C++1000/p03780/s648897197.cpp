#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for(auto& i: a) cin >> i;

  sort(begin(a), end(a));

  auto ok = [&](auto x) {
    if(K <= a[x]) return true;
    vector<bool> dp(K);
    dp[0] = true;
    for(auto i = 0; i < N; ++i) if(i != x) if(a[i] < K) {
      for(auto j = K-1; a[i] <= j; --j) dp[j] = dp[j] | dp[j - a[i]];
    }
    for(auto i = 0; i < K; ++i) if(dp[i]) if(K <= i + a[x]) return true;
    return false;
  };

  int l=-1, h=N;
  while(l+1 < h) {
    auto m=(l+h)/2;
    if(ok(m)) h = m;
    else      l = m;
  }
  cout << h << endl;
}
