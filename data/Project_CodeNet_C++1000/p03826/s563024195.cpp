#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,D,ans=0; cin >> A >> B >> C >> D;
  ans = max(A*B, C*D);
  cout << ans << endl;
}