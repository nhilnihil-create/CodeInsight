#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D ;
  cin >> A >> B >> C >> D;
  int ans =0;
  if (B>C&&A<=C&&B<D) ans = B-C;
  else if (D>A&&C<=A&&D<B) ans =D-A;
  else if (A<=C&&D<=B) ans =D-C;
  else if (C<=A&&B<=D) ans =B-A;
  else ans = 0;
  cout << ans << endl;
}
