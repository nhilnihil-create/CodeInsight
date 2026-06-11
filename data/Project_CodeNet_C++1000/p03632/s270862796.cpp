#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,D,X=0;
  cin >> A >> B >> C >> D;
  X += min(B,D)-max(A,C);
  if(X < 0){
    cout << 0 << endl;
    return 0;
  }
  cout << X << endl;
}
