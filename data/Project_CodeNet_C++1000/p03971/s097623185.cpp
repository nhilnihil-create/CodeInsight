#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;

  vector<string> ans(n);
  int cnt_a = 0, cnt_b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' &&  cnt_a + cnt_b < a + b) {
      ans[i] = "Yes";
      cnt_a++;
    }
    else if (s[i] == 'b' &&  cnt_a + cnt_b < a + b &&  cnt_b < b) {
      ans[i] = "Yes";
      cnt_b++;
    }
    else {
      ans[i] = "No";
    }
  }


  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}