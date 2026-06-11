#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec(N);
  for (int i = 0; i < M; i++) {
    int j, k;
    cin >> j >> k;
    vec.at(j - 1) += 1;
    vec.at(k - 1) += 1;
  }
  for (int i = 0; i < N; i++) {
    cout << vec.at(i) << endl;
  }
}