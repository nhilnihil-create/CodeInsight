#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int ans1 = A * B;
  int ans2 = C * D;
  if(ans1 >= ans2)
    cout << ans1 << "\n";
  else
    cout << ans2 << "\n";
  return 0;
}
