#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, ss=0, fin=0;
  cin >> A >> B >> C;
  set<int> S;
  for (int i=1; i<=100000; i++) {
    if (A*i%B==C) {
      fin=1;
      break;
    }
  }
  if (fin==1) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
