#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M, a, b;

  cin >> N >> M;
  vector<int> vec(N);

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    for (int j = 0; j < N; j++) {
      if (a == j + 1 || b == j + 1) {
        vec.at(j) += 1;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << vec.at(i) << endl;
  }

}