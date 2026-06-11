#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int ans = 2;
  int max = 1;
  cin >> N;

  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }

  for (int i = 2; i <= N; i += 2) {
    int count = 0;
    int j = i;
    while (j % 2 == 0) {
      j = j / 2;
      count++;
    }

    if (max < count) {
      max = count;
      ans = i;
    }
  }

  cout << ans << endl;
}