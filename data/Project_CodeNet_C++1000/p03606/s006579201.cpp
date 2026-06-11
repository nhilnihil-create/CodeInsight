#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, sum;
  cin >> A;

  sum = 0;
    
  for(int i = 0; i < A; i++){
  int L, R;
  cin >> L >> R ;
  sum += ( R - L)  ;
  }
  cout << sum + A << endl;
}
 