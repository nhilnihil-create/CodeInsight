#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, from, to, sum = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> from >> to;
    sum += to - from + 1;
  }
  cout << sum << endl;
}
