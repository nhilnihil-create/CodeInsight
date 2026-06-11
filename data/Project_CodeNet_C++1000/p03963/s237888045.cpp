#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main() {
  int N=0, K=0;
  cin >> N >> K;
  long long ans = K;
  rep(n, N-1){
    ans *= (K-1);
  }
  cout << ans << endl;
}