#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  vector<bool> list(26, false);
  for (int i = 0; i < s.size(); i++) {
    list[s[i] - 'a'] = true;
  }
  for (int i = 0; i < 26; i++) {
    if (list[i] == false) {
      cout << char('a' + i) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}