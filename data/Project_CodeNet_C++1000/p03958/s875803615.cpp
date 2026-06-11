#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, T;
  cin >> K >> T;
  vector<int> A(T);
  for (int i = 0; i < T; i++) cin >> A.at(i);
  
  int H = -1;
  for (int i = 0; i < T; i++) {
    if (A.at(i) > (K + 1) / 2) {
      H = A.at(i);
      break;
    }
  }
  
  if (H == -1) cout << 0 << endl;
  else cout << 2 * H - K - 1 << endl;
}

