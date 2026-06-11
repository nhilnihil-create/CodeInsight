#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int n0, n4;
  n0 = 0;
  n4 = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a % 2 == 1) n0++;
    else if (a % 4 == 0) n4++;
  }
  
  if (n0 + n4 == N) {
    if (n0 <= n4 + 1) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else {
    if (n0 <= n4) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
