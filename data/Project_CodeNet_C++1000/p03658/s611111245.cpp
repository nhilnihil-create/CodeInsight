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
  int N, K;
  cin >> N >> K;

  vector<int> l(N);
  for (int i = 0; i < N; i++) {
    cin >> l.at(i);
  }
  
  // 計算
  rsort_vec(l);
  int sum = 0;
  for (int i = 0; i < K; i++) {
    sum += l.at(i);
  }
  
  // 出力
  println(sum);
}
