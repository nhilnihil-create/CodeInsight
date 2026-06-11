#include <bits/stdc++.h>
using namespace std;

//ライブラリ始まり

//定数

//円周率
const double PI = 3.1415926535897932384;

//天井
const int INF = 1000000000; // = 10^9
const int64_t LINF = 1000000000000000; // = 10^15

//関数

//ctoi
int ctoi(char c){
  if (c == '0') {
    return 0;
  }
  if (c == '1') {
    return 1;
  } 
  if (c == '2') {
    return 2;
  } 
  if (c == '3') {
    return 3;
  }
  if (c == '4') {
    return 4;
  } 
  if (c == '5') {
    return 5;
  } 
  if (c == '6') {
    return 6;
  }
  if (c == '7') {
    return 7;
  } 
  if (c == '8') {
    return 8;
  } 
  if (c == '9') {
    return 9;
  }
  return -1;  
}

//素数判定
bool PN(int x) {
  if (x <= 1) {
    return false;
  }
  if (x == 2) {
    return true;
  }
  for (int i = 2; i < sqrt(x) + 1; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

//ライブラリ終わり
 
int main() {
  int N;
  cin >> N;
  vector<int> M(100000, 0);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    M.at(A - 1)++;
  }
  int ans = 0;
  int C = 0;
  for (int i = 0; i < 100000; i++) {
    if (M.at(i) > 0) {
      ans++;
    }
    if (M.at(i) > 1) {
      if ((M.at(i) + C) % 2 == 0) {
        C = 1;
      }
      else {
        C = 0;
      }
    }
  }
  cout << ans - C << endl;
}