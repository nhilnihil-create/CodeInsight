#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  ll N, K;
  cin >> N >> K;
  
  vector<pair<ll, ll>> vec(N);
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    
    vec[i] = {a, b};
  }
    
  sort(vec.begin(), vec.end());
  
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    sum += vec[i].second;
    
    if (sum >= K) {
      cout << vec[i].first << endl;
      return 0;
    }
  }
}