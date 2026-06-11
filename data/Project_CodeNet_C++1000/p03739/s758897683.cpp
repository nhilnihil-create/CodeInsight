#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long a[n], s[n], sum = 0, cnt = 0, num = 0, ans;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    sum += a[i];
    s[i] = sum;
  }
  for (int i=0; i<n; i++) {
    if (i%2) {
      if (s[i]+num<0)
        continue;
      cnt += s[i]+num+1;
      num = -s[i]-1;
    } else {
      if (s[i]+num>0)
        continue;
      cnt += -s[i]-num+1;
      num = -s[i]+1;
    }
  }
  ans = cnt;
  cnt = 0;
  num = 0;
  for (int i=0; i<n; i++) {
    if (i%2) {
      if (s[i]+num>0)
        continue;
      cnt += -s[i]-num+1;
      num = -s[i]+1;
    } else {
      if (s[i]+num<0)
        continue;
      cnt += s[i]+num+1;
      num = -s[i]-1;
    }
  }
  ans = min(ans, cnt);
  cout << ans << endl;
  return 0;
}