#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 5;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> list(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> list[i];
  }
  vector<ll> aup;
  ll start = list[0] + 1;
  for (int i = 1; i < n; i++) {
    aup.push_back(list[i]);
  }
  int uplen = aup.size();
  k--;

  ll mincost = LLONG_MAX;
  for (int bit = 0; bit < (1<<uplen); bit++) {
    vector<int> ss(uplen, 0);
    int cnt = 0;
    for (int i = 0; i < uplen; i++) {
      if (bit>>i&1) {
        ss[i] = 1;
        cnt++;
      }
    }

    if (cnt == k) {
      ll cstart = start;
      ll sum = 0;
      for (int j = 0; j < uplen; j++) {
        if (ss[j]) {
          if (cstart < aup[j]) {
            cstart = aup[j] + 1;
          } else {
            sum += (cstart - aup[j]);
            cstart++;
          }
        } else {
          if (cstart < aup[j]) {
            cstart = aup[j] + 1;
          }
        }
      }
      mincost = min(mincost, sum);
    }
  }
  cout << mincost << endl;
  return 0;
}