#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;

// N!の約数の個数の%MODを求める
ULL FactorsOfFactorial(ULL n) {

  const ULL MOD = 1000000007;

  ULL result = 1;
  vector<ULL> v(n + 1);

  // N!なのでNまでループ
  for (ULL i = 2; i <= n; i++) {
    ULL x = i;

    // 素因数分解結果を配列に記録
    for (ULL j = 2; 1 < x; j++) {
      while (x % j == 0) {
        v.at(j)++;
        x /= j;
      }
    }
  }

  // (n1+1)(n2+1)(n3+1)...%MOD
  for (ULL i = 2; i <= n; i++) {
    result = (result * (v.at(i) + 1)) % MOD;
  }

  return result;
}

int main() {
  ULL N;
  cin >> N;
  cout << FactorsOfFactorial(N) << endl;
  getchar();
}

// int型,unsigned型では正解が出ない

// 入出力例
// 3
// 4

// 6
// 30

// 1000
// 972926972