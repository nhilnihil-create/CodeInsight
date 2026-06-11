#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int win = 0, lose = 0;
  for (int i = 0; i < s.length(); i++) {
    win += i%2 && s[i] == 'g';
    lose += !(i%2) && s[i] == 'p';
  }
  cout << win-lose;
}