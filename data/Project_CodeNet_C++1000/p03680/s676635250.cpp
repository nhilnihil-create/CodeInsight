#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int push = 0;
  vector<int> a(n+1, 0);
  for (int i = 1; i <= n; i++) cin >> a[i];
  set<int> s;
  int touch = 1;
  while(true) {
    s.insert(touch);
    touch = a[touch];
    push++;
    if(touch == 2) break;
    else if(s.count(touch)) {
      push = -1;
      break;
    }
  }
  cout << push;
}