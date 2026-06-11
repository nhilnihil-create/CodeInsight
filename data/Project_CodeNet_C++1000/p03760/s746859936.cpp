#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  for (int i = 0; i < S.size(); i++) {
    cout << S.at(i);
    if (i < T.size()) cout << T.at(i);
  }
  cout << "\n";
}