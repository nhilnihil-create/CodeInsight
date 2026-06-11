#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  string a = "abcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i < 26; i++) {
    for (int j = 0, l = S.size(); j < l; j++) {
      if (S[j] == a[i]) {
        break;
      }
      if (j == l - 1 && S[j] != a[i]) {
        cout << a[i] << endl;
        return 0;
      }
    }
  }

  cout << "None" << endl;
}