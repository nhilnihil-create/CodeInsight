#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  int ans = 0;
  cin >> A >> B >> C;
  
  while(A%2 == 0 && B%2 == 0 && C%2 == 0){
    ans += 1;
    int a =A,b=B,c=C;
    A = b/2 + c/2;
    B = a/2 + c/2;
    C = a/2 + b/2;
    if(A == B && A == C){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
