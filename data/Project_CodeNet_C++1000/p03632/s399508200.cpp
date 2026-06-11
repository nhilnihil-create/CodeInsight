#include <bits/stdc++.h>

using namespace std;

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int s, e;
  s = A;
  e = B;
  if(C > A){
    s = C;
  }
  if(D < B){
    e = D;
  }
  if(e-s > 0){
  cout << e - s << endl;
  }else{
  cout << 0 << endl;
  }
}
