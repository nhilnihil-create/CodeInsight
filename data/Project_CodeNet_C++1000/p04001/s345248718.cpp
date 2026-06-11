#include <bits/stdc++.h>
using namespace std;

void recursive_comb(int *indexes, int s, int rest, function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main() {
  // 入力
  string S;
  cin >> S;
  
  // 間の数
  int m = (int)(S.size() - 1);
  
  long sum = 0;
  for (int i = 0; i <= m; i++) { // +の数
    // mCiの組み合わせごとに処理する
    foreach_comb(m, i, [&sum, S, i](int *indexes) {
      int p = 0;
      for (int j = 0; j < i; j++) {
        int len = indexes[j] + 1 - p;
        sum += atol(S.substr(p, len).c_str());
        p = p + len;
      }
      sum += atol(S.substr(p).c_str());
    });
  }
  
  cout << sum << endl;
}
