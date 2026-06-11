#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size() - 1;
  uint64_t sum;
  
  for (int i = 0; i < (1 << N); i++) { // ビット全探索 iが表すのは符号を入れる箇所
    string ss = ""; // バッファ
    for (int j = 0; j < S.size(); j++) {
      ss += S[j]; // 符号が来るまでバッファに文字を足していく
      if ((i >> j) & 1) { // j番目のビットが1の(j番目に符号を入れる)とき
        sum += stoll(ss); // バッファ内の数値を加算
        ss = ""; // バッファクリア
      }
    }
          
    sum += stoll(ss);
  }
  
  cout << sum << endl;
}
