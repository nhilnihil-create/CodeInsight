#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  int X = A*B;
  int Y = C*D;
  if(X<Y){
    cout << Y << endl;
  }
  else{
    cout << X << endl;
  }
}
