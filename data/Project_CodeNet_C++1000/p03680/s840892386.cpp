#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, k;
  cin >> N;
  vector<int> vec(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
    vec.at(i)--;
  }
  
  k = vec.at(0);
  for (int i = 0; i < N; i++) {
    if (k == 1) {
      cout << i + 1 << endl;
      break;
    } else if (i == N - 1) {
      cout << -1 << endl;
    } else {
      k = vec.at(k);
    }
  }
}
