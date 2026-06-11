#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define println(msg) cout << msg << endl

int f(LL a, LL b) {
  int ac = 0;
  while (a > 0) {
    a /= 10;
    ac ++;
  }
  int bc = 0;
  while (b > 0) {
    b /= 10;
    bc ++;
  }
  return max(ac, bc);
}

int main() {
  // 入力
  LL N;
  cin >> N;

  // 計算
  LL minNum = N + 1;
  for (LL a = 1; a <= (LL)sqrt(N); a++) {
    if ((N % a) == 0) {
      LL b = N / a;
      minNum = min((LL)f(a, b), minNum);
    }
  }
  
  // 出力
  println(minNum);
}