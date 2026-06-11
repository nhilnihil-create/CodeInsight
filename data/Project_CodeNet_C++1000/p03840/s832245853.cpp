#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long I, O, T, J, L, S, Z;
  cin >> I >> O >> T >> J >> L >> S >> Z;
  long long ans = 0;
  if(I > 0 && J > 0 && L > 0 && I % 2 + J % 2 + L % 2 >= 2){
    ans += 3;
    I--;
    L--;
    J--;
  }
  ans += 2 * (I / 2);
  ans += 2 * (J / 2);
  ans += 2 * (L / 2);
  ans += O;
  cout << ans << endl;
  return 0;
}
