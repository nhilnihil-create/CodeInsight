#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string s;
  cin >> s;

  int count[26] = {0};

  for (char c: s) count[c - 'a']++;

  for (int x: count) {
    if (x & 1) {
      cout << "No" << "\n";
      return 0;
    }
  }
  cout << "Yes" << "\n";
}
