#include<bits/stdc++.h>
using namespace std;

#define MAX_LEN 10

int main()
{
  string s; cin >> s;
  int slen = s.length();
  
  int64_t sum = 0;
  for (int i = 0; i < (1 << MAX_LEN); i++) {
    bitset<MAX_LEN> bit(i);
    string num = "";
    for (int j = 0; j < slen; j++) {
      if (bit.test(j)) {
        // ビットが立っていたら連結する
        num += s.at(j);
      } else if (num != "") {
        // 101のように離れている場合、例えば入力が125のとき1+5となるようにする
        sum += stoll(num);
        num = "";
      }
    }
    // ループを抜けたときに連結されている数を足す
    if (num != "") {
      sum += stoll(num);
    }
    if (bit.count() == slen) {
      // 入力された文字列長まで調べ終わったので抜ける
      break;
    }
  }
  
  cout << sum << endl;
}