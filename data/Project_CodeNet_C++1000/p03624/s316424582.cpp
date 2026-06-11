#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  set<char> st;
  rep(i, S.size()) st.insert(S[i]);

  for (int i = 0; i < 26; i++) {
    if (!st.erase((char)('a' + i))) {
      cout << (char)('a' + i) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}