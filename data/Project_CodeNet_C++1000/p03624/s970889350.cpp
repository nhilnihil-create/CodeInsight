#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string s; cin >> s;
  bool char_found[26] = {0};

  for (char c: s) {
    char_found[c - 'a'] = true;
  }

  for (int i = 0; i < 26; ++i) {
    if (!char_found[i]) {
      cout << static_cast<char>('a' + i) << "\n";
      return 0;
    }
  }

  cout << "None" << "\n";
}
