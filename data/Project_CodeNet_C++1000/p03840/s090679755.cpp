#include <bits/stdc++.h>
using namespace std;
int main(){
  long long I, O, T, J, L, S, Z;
  cin >> I >> O >> T >> J >> L >> S >> Z;
  long long tmp1 = I / 2 * 2 + J / 2 * 2 + L / 2 * 2;
  long long tmp2 = 0;
  if (I > 0 && J > 0 && L > 0){
    tmp2 += 3 + (I - 1) / 2 * 2 + (J - 1) / 2 * 2 + (L - 1) / 2 * 2;
  }
  cout << O + max(tmp1, tmp2) << endl;
}