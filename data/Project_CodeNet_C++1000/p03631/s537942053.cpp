#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  
  // コピーコンストラクタ
  string reverseN(N);
  reverse(reverseN.begin(), reverseN.end());

  cout << (N == reverseN ? "Yes" : "No") << endl;
}