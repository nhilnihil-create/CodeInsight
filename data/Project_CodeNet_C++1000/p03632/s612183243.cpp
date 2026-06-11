#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int StartTime = max(A, C);
  int EndTime   = min(B, D);

  cout << max(0, EndTime - StartTime) << endl;
}
