#include <bits/stdc++.h>
using namespace std;
#define ll long long

//ライブラリ始まり

//定数

//円周率
const double PI = 3.1415926535897932384;

//天井
const int INF = 1000000000; // = 10^9
const ll LINF = 1000000000000000; // = 10^15

//ABC文字列
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZABC";
const string abc = "abcdefghijklmnopqrstuvwxyzabc";

//よくあるmodくん
const ll MOD = 1000000007; // = 10^9 + 7

//データ構造

//Union_Find木
struct UnionFind {
  vector<int> UF; // UF.at(i) : iの親の番号
  UnionFind(int N) : UF(N) { // 最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++) {
      UF.at(i) = i;
    }
  }
  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (UF.at(x) == x) {
      return x;
    }
    return UF.at(x) = root(UF.at(x));
  }
  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x); // xの根をrx
    int ry = root(y); // yの根をry
    if (rx == ry) {
      return; // xとyの根が同じ(=同じ木にある)時はそのまま
    }
    UF.at(rx) = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }
  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

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
    return false; // 1や0,-1は素数ではない
  }
  if (x == 2) {
    return true; // √2 + 1 > 2 なので下でやると 2 ％ 2 = 0 となり判定できない
  }
  for (int i = 2; i < sqrt(x) + 1; i++) {
    if (x % i == 0) {
      return false; // 割れたら素数じゃない
    }
  }
  return true;
}

//ライブラリ終わり

int main() {
  string S;
  cin >> S;
  vector<char> ANS;
  for (int i = 0; i < int(S.size()); i++) {
    if (S.at(i) != 'B') {
      ANS.push_back(S.at(i));
    }
    else if (ANS.size() != 0) {
      ANS.pop_back();
    }    
  }
  for (int i = 0; i < int(ANS.size()); i++) {
    cout << ANS.at(i);
  }
  cout << endl;
}