#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A;
  int c = 1;
  cin >> A;
  rep(i, 10000) {
    if(c > A) {
      break;
    }
    c *= 2;
  }
  cout << c / 2 << endl;
}
    