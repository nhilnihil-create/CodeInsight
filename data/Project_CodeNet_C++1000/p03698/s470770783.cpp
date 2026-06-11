#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  sort(all(s));
  for (int i = 1; i < s.size(); i++) {
    if (s[i - 1] == s[i]) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}