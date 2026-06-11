#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  for (char i = 'a'; i <= 'z'; i++) {
    int cnt = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == i) cnt++;
    }
    if (cnt % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}