#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t Q,H,S,D,N;
  cin >> Q >> H >> S >> D >> N;

  int64_t P1= min(S, min(4*Q, 2*H));
  int64_t P2= min(D, 2*P1);

  int64_t ans= (N%2==1) ? P2*(N/2)+ P1
                        : P2*(N/2);
  cout << ans << endl;
}