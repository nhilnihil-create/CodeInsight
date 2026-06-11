#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int K, S;
  cin >> K >> S;
  int co = 0;
  rep(i, K) {
    rep(j, K) {
      if(max(0, S - K) <= i + j && i + j <= S) {
        co++;
      }
    }
  }
  cout << co << endl;
}