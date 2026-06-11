#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int M = 0;
  int s;
  for (int i = 0; i < N-1; i++) {
    if (M < a[i]+a[i+1]) {
      M = a[i]+a[i+1]; s = i+1;
    }
  }
  if (M < L) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;

  for (int i = 1; i < s; i++) {
    cout << i << endl;
  }
  for (int i = N-1; i > s; i--) {
    cout << i << endl;
  }
  cout << s << endl;
}