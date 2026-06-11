#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans;
  bool flag;
  long long cnt=0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  if (v[0] == 1) cout << "-1" << endl;
  else {
    ans = v[0];
    while (true) {
      cnt++;
      if (ans == 2) {
        cout << cnt << endl;
        break;
      }
      else if (cnt >= n) {
       cout << "-1" << endl;
        break;
      }
      else {
        ans = v[ans-1];
      }
    }
  }
}