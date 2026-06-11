#include <bits/stdc++.h>
using namespace std;

int n;
long long mod = 1e9 + 7;
long long calc(vector<int> &v, int idx, long long acc) {
  if (idx == n) {
    return acc;
  }
  return calc(v, idx + 1, (acc * (v[idx] - idx)) % mod);
}
int main() {
  cin>>n;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  vector<int> cnt(n);
  cnt[0] = n;
  int prev = 1;
  int seq = 1;
  for (int i=1; i<n; i++) {
    cnt[i] = cnt[i-1];
    if (a[i] - prev > 1) {
      prev += 2;
      if (seq % 2 == 0) {
        --cnt[i];
      }
      seq = 1;
    } else {
      ++seq;
      if (seq % 2 == 1) {
        --cnt[i];
      }
    }
  }

  reverse(cnt.begin(), cnt.end());
  cout<<calc(cnt, 0, 1)<<endl;
}