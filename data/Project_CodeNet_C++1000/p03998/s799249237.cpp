#include <bits/stdc++.h>
using namespace std;


void solve() {
  map<char, string> mp;
  cin >> mp['A'] >> mp['B'] >> mp['C'];
  char turn = 'A';
  while(1) {
    if(mp[turn].empty()) {
      cout << turn;
      return;
    }
    char temp = mp[turn][0];
    mp[turn].erase(0,1);
    turn = toupper(temp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
