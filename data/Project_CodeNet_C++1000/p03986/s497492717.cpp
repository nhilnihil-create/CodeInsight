#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int N = s.size();
  int m = 0, p = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'T') p++;
    else p--;
    m = max(m,p);
  }
  cout << 2*m << endl;
}