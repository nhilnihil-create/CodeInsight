#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int64_t A, B, C;
  cin >> A >> B >> C;
  if(A % C == 0) {
    cout << B / C - A / C + 1 << endl;
  }
  else {
    cout << B / C - A / C << endl;
  }
}
