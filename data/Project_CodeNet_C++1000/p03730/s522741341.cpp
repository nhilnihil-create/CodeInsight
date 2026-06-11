#include <bits/stdc++.h>
using namespace std;



void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int ca = a;
  int x = (a%b);
  if(x == c%b) {
    cout << "YES";
    return;
  }
  a += ca;
  while((a%b) != x) {
    if(a%b == c%b) {
      cout << "YES";
      return;
    }
    a += ca;
  }
  cout << "NO";
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
