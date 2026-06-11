#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  string s; cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    int a = i + 1, b = i + 2;
    if (a < n && s[i] == s[a]) {
      cout << i+1 << " " << a+1 << endl;
      return 0;
    }
    if (b < n && s[i] == s[b]) {
      cout << i+1 << " " << b+1 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}