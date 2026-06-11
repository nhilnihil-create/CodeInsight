#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  int g = 0, p = 0;
  for(auto it : s) {
    if(it == 'g') g++;
    if(it == 'p') p++;
  }

  cout << (g - p) / 2 << '\n';
}