#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  Int N, K;
  cin >> N >> K;
  
  Int ans = K;
  rep(i, N-1) {
    ans *= (K-1);
  }
  
  cout << ans << endl;

}