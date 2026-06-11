#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for(int i=0; i<=a; i++) {
    for(int j=0; j<=a; j++) {
      if(0 <= b-(i+j) && b-(i+j) <= a) ans++;
    }
  }
  cout << ans << endl;
}