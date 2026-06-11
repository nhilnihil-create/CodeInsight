#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string A, B;
  cin >> A >> B;
  int N = A.size(), M = B.size();
  if (N > M) {
    cout << "GREATER" << endl;
  }
  else if (N < M) {
    cout << "LESS" << endl;
  }
  else if(A > B) {
    cout << "GREATER" << endl;
  }
  else if(A < B) {
    cout << "LESS" << endl;
  }
  else {
    cout << "EQUAL" << endl;
  }
  return 0;
}
