#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i;
  string s, t;
  cin >> n >> s >> t;
  for(i = 0; i < n; i++) {
    int f = 1;
    for(int j = i; j < n; j++)
      if(s[j] != t[j - i]) f = 0;
    if(f) break;
  }
  cout << n * 2 - (n - i) << "\n";
}