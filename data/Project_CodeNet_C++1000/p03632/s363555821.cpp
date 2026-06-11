#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B,C,D; cin >> A >> B >> C >> D;
  if(C>B || A>D) cout << 0 << endl;
  else if(A<=C && B>D) cout << D- C << endl;
  else if(A>C && B<=D) cout << B-A << endl;
  else if(A>C && B>D) cout << D-A << endl;
  else if(A<=C && B <=D) cout << B-C << endl;
}