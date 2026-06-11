#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int middle = K / 2;
  int distance = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    if (x <= middle) {
      distance += x * 2;
    } else {
      distance += (K - x) * 2;
    }
  }

  cout << distance << endl;
}