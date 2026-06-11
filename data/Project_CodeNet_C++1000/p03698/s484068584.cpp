#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  vector<int> alphabet(26, 0);
  for (int i = 0; i < S.size(); i++) alphabet[(int)S[i] - 97]++;
  bool same = false;
  for (int i = 0; i < 26; i++) {
    if (alphabet[i] > 1) {
      same = true;
      break;
    }
  }
  if (same) cout << "no" << endl;
  else cout << "yes" << endl;
}
