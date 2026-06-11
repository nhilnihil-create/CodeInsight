#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main() {
  int A=0, B=0, C=0;
  bool flag = false;
  cin >> A >> B >> C;
  // あまりの問題は周期に注目
  // 今回はたかだか割る数のB分だけ調べればOK
  rep(b, B){
    if ((A * (b+1)) % B == C) flag = true;
  }
  if (flag==true) cout << "YES" << endl;
  else cout << "NO" << endl;
}