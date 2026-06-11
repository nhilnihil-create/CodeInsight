#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int w, a, b;
  cin >> w >> a >> b;
  if(a<=b) {
    if(b-(a+w)>=0) cout << b-(a+w) << endl;
    else cout << 0 << endl;
  }
  else {
    if(a-(b+w)>=0)cout << a-(b+w) << endl;
    else cout << 0 << endl;
  }
  return 0;
}