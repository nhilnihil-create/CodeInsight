#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int cost = 0;
  for (int i = 0; i < S.size() - 1; i++) {
    char lhs = S.at(i);
    char rhs = S.at(i + 1);
    if (lhs != rhs) cost++;
  }
  cout << cost << endl;
}