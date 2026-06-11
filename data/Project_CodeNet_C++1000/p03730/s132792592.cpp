#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  int a[B];
  FOR(i,0,B) a[i] = A*(i+1);
  FOR(i,0,B) {
    if ((a[i] % B) == C) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  
  return 0;
  
}


