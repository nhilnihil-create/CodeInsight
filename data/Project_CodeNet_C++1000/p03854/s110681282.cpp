#include <bits/stdc++.h>
using namespace std;

/*
regexを使う場合
  | -> or, どれか
  * -> 直前の文字を0回以上繰り返す
  ? -> 直前の文字を0回か1回繰り返す
*/ 

int main() {
  string s;
  cin >> s;
  // (dream(er)?|eraser?)* でも良い
  cout << (regex_match(s, regex("(dream|dreamer|erase|eraser)*")) ? "YES" : "NO") << endl;
}