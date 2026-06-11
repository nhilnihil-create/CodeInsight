//#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int main() {
  int a, b;
  string op;
  cin >> a >> op >> b;
  int ans = 0;
  // ここにプログラムを追記
  if(op == "+") {
    ans = a + b;
  } else {
    ans = a - b;
  }
  cout << ans << endl;
  return 0;
}
