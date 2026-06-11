#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  int cnt = 0;
  int b_cnt = 0;
  for (int i = 0; i < n; i++) {
    bool pass = false;
    if (s.at(i) == 'a' && cnt < a + b) {
      pass = true;
    }
    else if (s.at(i) == 'b' && cnt < a + b && b_cnt < b) {
      pass = true;
      b_cnt++;
    }
    if (pass) {
      cout << "Yes" << endl;
      cnt++;
    }
    else {
      cout << "No" << endl;
    }
  }
  return 0;
}


