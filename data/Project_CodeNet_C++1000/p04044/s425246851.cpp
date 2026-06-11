#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define sort_vec(vec) sort(vec.begin(), vec.end())

int main() {
  // 入力
  int N, L;
  cin >> N >> L;

  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  
  // 計算
  sort_vec(S);
  string result = "";
  for (auto s : S) {
    result += s;
  }
  
  // 出力
  println(result);
}