// ABC 065 B- Trained?
// 配列の練習

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int N;
  cin >> N;

  // とりあえず格納
  vector<int> vec(N);
  rep(i, N) {
    cin >> vec.at(i);
  }
  // N回だめだったらなんかいやっても２にならない
  int n = 1, count = 0;
  rep(i, N) {
    n = vec.at(n-1);
    count++;
    if (n == 2) {
      break;
    }
  }
  // 光っているかの判断
  if (count < N) {
    cout << count << endl;
  }
  else {
    cout << "-1" << endl;
  }
}