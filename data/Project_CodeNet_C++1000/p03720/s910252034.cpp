#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,x;
  cin >> N >> M;
  vector<int> cnt(N);
  for (int i = 0; i < 2*M; i++) {
    cin >> x;
    for (int j = 0; j < N; j++) {
      if (x == j+1) {
        cnt.at(j)++;
        break;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << cnt.at(i) << endl;
  }
}