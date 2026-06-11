#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int A,B,X;
  cin >> A >> B >> X;
  if ((A != 0) && (B!=0)){
    cout << B/X - (A-1)/X << endl;
    return 0;
  }
  else if(A == 0 && (B != 0)){
    cout << B/X+1 << endl;
    return 0;
  }
    cout << 1 << endl;
}
