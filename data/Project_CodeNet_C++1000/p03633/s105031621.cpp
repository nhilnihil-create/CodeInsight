#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, ans;
  cin >> N;
  vector<ll> T(N);
  for(ll i = 0; i < N; i++) {
    cin >> T.at(i);
    if(i == 0) ans = T.at(0);
    else ans = lcm(ans, T.at(i));
  }
  cout << ans << endl;
}