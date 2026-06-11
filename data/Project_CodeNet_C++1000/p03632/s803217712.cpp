#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int start = max(A, C), stop = min(B, D);
  cout << max(0, stop - start) << endl;
}