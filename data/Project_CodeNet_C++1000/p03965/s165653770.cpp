#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (i%2) ans += (s[i] == 'p') ? 0 : 1;
    else ans += (s[i] == 'g') ? 0 : -1;
  }
  cout << ans << endl;
}