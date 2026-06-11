#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef long long ll;
ll dp[200010];
int main() {
  string a;
  cin >> a;
  vector<ll> count(26);
  dp[0] = 1;
  int n = a.size();
  for (ll i = 0; i < n; ++i) {
    dp[i+1] = dp[i]+i-count[a[i]-'a'];
    ++count[a[i]-'a'];
  }
  cout << dp[n] << endl;
}