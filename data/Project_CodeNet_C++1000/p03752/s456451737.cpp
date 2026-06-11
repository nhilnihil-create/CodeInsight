#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int (i)=0;(i)<(n);(i)++)
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  long long ans = LLONG_MAX;
  rep(i, pow(2, n)) {
    bitset<32> b(i);
    int num = 0;
    rep(j, 32) {
      if(b.test(j)) num++;
    }
    if(num < k || !b.test(0)) continue;
    long long alt = 0;
    int max = 0;
    rep(j, n) {
      if(j == 0) max = a[j];
      else {
        if(a[j] > max) {
          max = a[j];
          continue;
        }
        else if(b.test(j)){
          alt += (max + 1) - a[j];
          max += 1;
        }
      }
    }
    if(alt < ans) ans = alt;
  }

  cout << ans << endl;
}