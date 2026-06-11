#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t Q,H,S,D;
  cin >> Q >> H >> S >> D;
  int64_t N;
  cin >> N;
  H=min(H,Q*2);
  S=min(S,H*2);
  D=min(D,S*2);
  int64_t s,d;
  d=N/2;
  N%=2;
  s=N;
  cout << d*D+s*S << endl;
  return 0;
}
