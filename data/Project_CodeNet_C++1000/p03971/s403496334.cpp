#include <bits/stdc++.h>
using namespace std;

long long n, a, b;
string s;

int main() {
  cin >> n >> a >> b >> s;
  int suma = 0, sumb = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a' && suma + sumb < a + b) {
      ++suma;
      cout << "Yes" << endl;
    } else if (s[i] == 'b' && suma + sumb < a + b && sumb < b) {
      ++sumb;
      cout << "Yes" << endl;
    } else
      cout << "No" << endl;
  }
  return 0;
}
