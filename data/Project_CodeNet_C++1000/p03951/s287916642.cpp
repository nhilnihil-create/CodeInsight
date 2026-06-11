#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int ctoi(const char c) {
    if ('0' <= c && c <= '9') return (c - '0');
    return -1;
}
vector<int> input(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    return vec;
}
void output(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return;
}
vector<vector<int>> input(int n, int m) {
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table. at(i).at(j);
        }
    }
    return table;
}
void output(vector<vector<int>> table) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table.at(0).size(); j++) {
            cout << table.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
long long perm(int n, int r) {
    if (n < r) {
        cout << "error" << endl;
        return 0;
    }
    long long perm = 1;
    for (int i = n; i > n - r; i--) {
        perm *= i;
    }
    return perm;
}
long long comb(int n, int r) {
    if (n < r) {
        cout << "error" << endl;
        return 0;
    }
    long long comb = perm(n,r);
    for (int i = r; i > 0; i--) {
        comb /= i;
    }
    return comb;
}
long long homo(int n, int r) {
    return comb(n + r - 1, n - 1);
}
long long fact(int n) {
    long long fact = 1;
    for (int i = n; i > 0; i--) {
        fact *= i;
    }
    return fact;
}
int gcd(int a, int b){
    if (a % b == 0){
        return(b);
    }else{
        return(gcd(b, a % b));
    }
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
bool isprime(int n){
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
void sayYes(bool f) {
    if (f) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
void sayYES(bool f) {
    if (f) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
/*bool isok(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
  int h=board.size(),w=board.at(0).size();
 
  // 移動先がマス目の外
  if(x<=-1||x>=w||y<=-1||y>=h){
    return false;
  }
  // 移動先が壁マス
  if(board.at(y).at(x)=='#'){
    return false;
  }
  // 既に調べているマスへの移動は調べない
  if (checked.at(y).at(x)){
    return false;
  }
  // それ以外
  return true;
}
 
// (y, x)にいる状態からゴールに到達できるか
// board: マス目の種類
// checked: そのマスを既に調べたかを持つ二次元配列
bool reachable(vector<string> &board,vector<vector<bool>> &checked,int x,int y){
  int h=board.size(),w=board.at(0).size();
 
  // ベースケース
  if (board.at(y).at(x)=="goal"){
    // ゴールにいる状態
    return true;
  }
  // 再帰ステップ
  checked.at(y).at(x) = true;  // 既に調べているという状態に変えておく
  // 「上」「右」「下」「左」のいずれかの移動でゴールに到達できるか？
  bool result = false;
  // 上へ移動したマスからゴールに到達できるか？
  if (isok(board, checked, x, y - 1) && reachable(board, checked, x, y - 1)) {
    result = true;
  }
  // 右へ移動したマスからゴールに到達できるか？
  if (isok(board, checked, x + 1, y) && reachable(board, checked, x + 1, y)) {
    result = true;
  }
  // 下へ移動したマスからゴールに到達できるか？
  if (isok(board, checked, x, y + 1) && reachable(board, checked, x, y + 1)) {
    result = true;
  }
  // 左へ移動したマスからゴールに到達できるか？
  if (isok(board, checked, x - 1, y) && reachable(board, checked, x - 1, y)) {
    result = true;
  }
  return result;
}*/

int main() {
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  for(int i=0;i<n;i++){
    if(s==t){
      cout << n << endl;
      return 0;
    }else{
      n++;
      s.erase(0,1);
      t.pop_back();
    }
  }
}