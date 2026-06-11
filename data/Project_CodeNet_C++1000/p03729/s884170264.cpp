#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string a, b, c;
  cin >> a >> b >> c;
  bool ans = a.back() == b.front() && b.back() == c.front();
  if (ans) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}