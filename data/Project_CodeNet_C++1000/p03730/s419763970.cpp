#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  rep(i, B) {
    if (A*(i+1) % B == C) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
