#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  int64_t P = 1;
  rep(i, N) {
    P *= (i + 1) % 1000000007;
    P = P % 1000000007;
  }
  cout << P << endl;
}
