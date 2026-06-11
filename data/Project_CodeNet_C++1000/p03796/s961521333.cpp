#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main() {
  int N = 0;
  long long ans = 1;
  long long MOD = pow(10, 9) + 7;
  cin >> N;
  rep(n, N){
    ans *= n+1;
    ans %= MOD;
  }
  cout << ans << endl;
}