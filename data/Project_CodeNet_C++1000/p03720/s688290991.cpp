#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define rsort_vec(vec) sort(vec.rbegin(), vec.rend()) // greater<int>()
int sum_of_digits(int n) {
  int sum = 0;
  for (; n > 0; n /= 10) { sum += (n % 10); }
  return sum;
}

int main() {
  // 入力
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> vp(M);
  for (int i = 0; i < M; i++) {
    cin >> vp.at(i).first >> vp.at(i).second;
  }
  
  // 計算
  vector<int> V(N);
  for (auto &v : V) {
    v = 0;
  }
  
  for (int i = 0; i < M; i++) {
    V.at(vp.at(i).first - 1)++;
    V.at(vp.at(i).second - 1)++;
  }
  
  // 出力
  for (int i = 0; i < N; i++) {
    println(V.at(i));
  }
}
