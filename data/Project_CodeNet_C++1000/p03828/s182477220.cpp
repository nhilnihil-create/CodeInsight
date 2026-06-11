#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N;
  cin >> N;
  long long ans = 1; //初期値
  
  long long res[N] = {}; //素因数の数を入れるバケット(i番目の箱には素因数i+1の個数が入る)
  FOR(i,1,N+1) {
    int X = i;
    for(int j=2; j*j <= i; j++) {
      if(X%j != 0) continue;
      long long ex = 0; //指数
      while (X%j == 0) { //割れるだけ割る
        ex++;
        X /= j;
      }
      res[j-1] += ex;
    }
    if(X != 1) res[X-1]++;
  }
    
  //FOR(i,0,N) cout << res[i] << endl;
  FOR(i,1,N) { //バケットの最初を除いて考える(1は素因数でないので考えない)
    if (res[i] > 0) {
      ans *= res[i]+1;
      ans %= 1000000007;
    }
  }
      
  cout << ans << endl;
  return 0;
}