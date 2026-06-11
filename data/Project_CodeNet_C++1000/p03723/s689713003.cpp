#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t A,B,C;
  cin >> A >> B >> C;
  int64_t sa=A;
  int64_t sb=B;
  int64_t sc=C;
  int64_t ta,tb,tc;
  for(int i=0;;i++){
    if((A%2!=0)||(B%2!=0)||(C%2!=0)){
      cout << i << endl;
      return 0;
    }
    ta=A;
    tb=B;
    tc=C;
    A=tb/2+tc/2;
    B=ta/2+tc/2;
    C=ta/2+tb/2;
    if((A==sa)&&(B==sb)&&(C==sc)){
      cout << -1 << endl;
      return 0;
    }
  }
  return 0;
}
