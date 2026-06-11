#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  
  int min, max;
  if (A > C) {
    min = A;
  } else {
    min = C;
  }
  if (B > D) {
    max = D;
  } else { 
    max = B;
  }
  
  if (max < min) {
    cout << 0 << endl;
  } else {
    cout << max - min << endl;
  }

}