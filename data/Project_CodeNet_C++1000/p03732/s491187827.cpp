#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(int argc, const char * argv[]) {
  ll N, W;
  cin >> N >> W;
  vector<ll> v1, v2, v3, v4;
  
  ll w1 = 0;
  for (int i = 0; i < N; i++) {
    ll wi, vi;
    cin >> wi >> vi;
    if (i == 0) {
      w1 = wi;
    }
    if (wi == w1 + 0) {
      v1.push_back(vi);
    }
    if (wi == w1 + 1) {
      v2.push_back(vi);
    }
    if (wi == w1 + 2) {
      v3.push_back(vi);
    }
    if (wi == w1 + 3) {
      v4.push_back(vi);
    }
  }
  sort(v1.begin(), v1.end(), greater<ll>());
  sort(v2.begin(), v2.end(), greater<ll>());
  sort(v3.begin(), v3.end(), greater<ll>());
  sort(v4.begin(), v4.end(), greater<ll>());
  
  int l1, l2, l3, l4;
  l1 = v1.size();
  l2 = v2.size();
  l3 = v3.size();
  l4 = v4.size();
  
  ll a1[l1 + 1] = {};
  ll a2[l2 + 1] = {};
  ll a3[l3 + 1] = {};
  ll a4[l4 + 1] = {};
  a1[1] = (l1 > 0) ? v1[0] : 0;
  a2[1] = (l2 > 0) ? v2[0] : 0;
  a3[1] = (l3 > 0) ? v3[0] : 0;
  a4[1] = (l4 > 0) ? v4[0] : 0;
  for (int i = 2; i < l1 + 1; i++) {
    a1[i] += (v1[i - 1] + a1[i - 1]);
  }
  for (int i = 2; i < l2 + 1; i++) {
    a2[i] += (v2[i - 1] + a2[i - 1]);
  }
  for (int i = 2; i < l3 + 1; i++) {
    a3[i] += (v3[i - 1] + a3[i - 1]);
  }
  for (int i = 2; i < l4 + 1; i++) {
    a4[i] += (v4[i - 1] + a4[i - 1]);
  }

  ll maxv= 0;
  for (int i1 = 0; i1 < l1 + 1; i1++) {
    for (int i2 = 0; i2 < l2 + 1; i2++) {
      for (int i3 = 0; i3 < l3 + 1; i3++) {
        for (int i4 = 0; i4 < l4 + 1; i4++) {
          ll w = w1 * i1 + (w1 + 1) * i2 + (w1 + 2) * i3 + (w1 + 3) * i4;
          if (w > W) {
            continue;
          }
          ll v = a1[i1] + a2[i2] + a3[i3] + a4[i4];
          maxv = max(maxv, v);
        }
      }
    }
  }

  cout << maxv << endl;
  return 0;
}
