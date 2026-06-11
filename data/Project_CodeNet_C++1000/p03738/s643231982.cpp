#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  int al = A.size();
  int bl = B.size();

  if (al > bl) {
    cout << "GREATER" << endl;
    return 0;
  }

  if (al < bl) {
    cout << "LESS" << endl;
    return 0;
  }

  for (int i = 0; i < al; i++) {
    if (A[i] > B[i]) {
      cout << "GREATER" << endl;
      return 0;
    }

    if (A[i] < B[i]) {
      cout << "LESS" << endl;
      return 0;
    }
  }

  cout << "EQUAL" << endl;
}