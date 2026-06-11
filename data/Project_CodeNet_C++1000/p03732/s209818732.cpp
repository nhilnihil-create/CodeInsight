#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
  ll N, W;
  cin >> N >> W;
  vector<ll> l1, l2, l3, l4;
  ll w1 = 0;
  for (int i = 0; i < N; i++) {
    ll wi, vi;
    cin >> wi >> vi;
    if (i == 0) {
      w1 = wi;
    }
    if (wi == w1 + 0) {
      l1.push_back(vi);
    }
    if (wi == w1 + 1) {
      l2.push_back(vi);
    }
    if (wi == w1 + 2) {
      l3.push_back(vi);
    }
    if (wi == w1 + 3) {
      l4.push_back(vi);
    }
  }
  sort(l1.begin(), l1.end(), greater<ll>());
  sort(l2.begin(), l2.end(), greater<ll>());
  sort(l3.begin(), l3.end(), greater<ll>());
  sort(l4.begin(), l4.end(), greater<ll>());

  vector<ll> l1s(l1.size() + 1, 0);
  vector<ll> l2s(l2.size() + 1, 0);
  vector<ll> l3s(l3.size() + 1, 0);
  vector<ll> l4s(l4.size() + 1, 0);

  for (int i = 0; i < l1.size(); i++) {
    l1s[i + 1] = l1s[i] + l1[i];
  }
  for (int i = 0; i < l2.size(); i++) {
    l2s[i + 1] = l2s[i] + l2[i];
  }
  for (int i = 0; i < l3.size(); i++) {
    l3s[i + 1] = l3s[i] + l3[i];
  }
  for (int i = 0; i < l4.size(); i++) {
    l4s[i + 1] = l4s[i] + l4[i];
  }

 ll ans = 0;
  for (int i = 0; i < l1s.size(); i++) {
    for (int j = 0; j < l2s.size(); j++) {
      for (int k = 0; k < l3s.size(); k++) {
        for (int l = 0; l < l4s.size(); l++) {
          if (w1 * i + (w1 + 1) * j + (w1 + 2) * k + (w1 + 3) * l <= W) {
            ans = max(ans, l1s[i] + l2s[j] + l3s[k] + l4s[l]);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
