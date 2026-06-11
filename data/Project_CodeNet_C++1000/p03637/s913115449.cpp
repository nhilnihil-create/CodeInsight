#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int cnt_4 = 0;
  int cnt_2 = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a % 4 == 0) {
      cnt_4++;
    } else if (a % 2 == 0) {
      cnt_2++;
    }
  }
  if (cnt_4 * 2 + 1 + max(cnt_2 - 1, 0) >= N) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
/* vim:set fdm=marker: */
