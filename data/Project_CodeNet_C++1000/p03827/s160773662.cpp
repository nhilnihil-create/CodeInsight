#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int N, mx=0, x=0;
  string S;
  cin >> N >> S;
  for (char c:S) {
    if (c=='I') {
      x++;
    }
    else {
      x--;
    }
    mx=max(mx, x);
  }
  cout << mx << endl;
}