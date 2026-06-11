#include <bits/stdc++.h>
using namespace std;
// for (int i = 0; i < N; i++) {
// strint'', char'
//エスケープシークエンス改行になる\n　cout << "こんにちは\nAtCoder";
// 行全て取り出す　getline(cin, 文字列変数);
// 配列　vector<型> vec(要素数, 初期値);　　vec.at(i)　　vec.size()
// int型 data[要素数]; // Cの配列

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  int count = 0;
  bool flag = true;
  int now = 1;
  for (int i = 0; i < n; i++) {
  	cin >> vec.at(i);
  }
  for (int i = 0; i < n; i++) {
    count++;
    now = vec.at(now-1);
    if (now == 2) { 
      cout << count << endl;
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << -1 << endl;
 }
 
}



