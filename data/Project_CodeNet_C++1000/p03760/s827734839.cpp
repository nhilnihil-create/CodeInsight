#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string O ,E;
  cin >> O >> E;

  for (int i = 0; i < O.size(); ++i) {
    if (i == O.size() - 1 && O.size() == E.size()) {
      cout << O.at(i) << E.at(i) << endl;
    }
    else if (i == O.size() - 1 && O.size() != E.size()) {
      cout << O.at(i) << endl;
    }
    else {
      cout << O.at(i) << E.at(i);
    }
  }
  return 0;
}
