#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define rsort_vec(vec) sort(vec.rbegin(), vec.rend()) // greater<int>()

int main() {
  // 入力
  int N;
  cin >> N;

  vector<int> a(3 * N);
  for (int i = 0; i < (3 * N); i++) {
    cin >> a.at(i);
  }
  
  // 計算
  sort_vec(a);

  // 小さい側のN個は、それぞれのチームの最弱に配置するので、使わない
  vector<int> b;
  for (int i = 0; i < (2 * N); i++) {
    b.push_back(a.at(i + N));
  }
  
  // 点数を最大化したいが、チームで一番強い人がもったいない
  // チームごとの1, 2位の差を最小化すれば、全体では最大になるはずという発想
  long sum = 0L;
  for (int i = 0; i < (2 * N); i+=2) {
    sum += b.at(i);
  }  
  
  // 出力
  println(sum);
}
