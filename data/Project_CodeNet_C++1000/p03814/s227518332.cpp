#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;

  int max_num = 0;
  int start = -1;
  rep(i, s.length()) {
    if (s.at(i) == 'A' && start == -1) {
      start = i;
    } else if (s.at(i) == 'Z' && start != -1) {
      max_num = max(max_num, i - start + 1);
    }
  }

  cout << max_num << endl;
  return 0;
}