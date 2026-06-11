#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  int odd_count = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] % 2 == 1) {
      odd_count++;
    }
  }

  if (odd_count % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
