#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y, Z;
  int ans =0;
  cin >> A >> B >> C;
  while(A%2==0 && B%2==0 && C%2 == 0){
    if(A==B && A==C){
      ans = -1;
      break;
    }
    X=A; Y=B; Z=C;
    A=(Y+Z)/2;
    B=(X+Z)/2;
    C=(Y+X)/2;
    ans++;
  }
  
  cout << ans << endl;
}
