#include "bits/stdc++.h"
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  int mx = max(A,max(B,max(C,D)));
  int mn = min(A,min(B,min(C,D)));
  cout << max((B-A)+(D-C)-(mx - mn),0) << endl;
  return 0;
}