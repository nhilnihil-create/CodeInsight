#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<int> V(26);
  for (auto c : S) V.at(c - 'a')++;
  for (int i = 0; i < 26; i++) {
    if (!V.at(i)) return cout << char('a' + i) << "\n", 0;
  }
  cout << "None" << "\n";
}