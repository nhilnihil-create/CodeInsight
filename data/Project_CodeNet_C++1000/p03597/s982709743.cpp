#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N,A,B;
  
  cin >> N;
  cin >> A;
  
  B = N*N ;
  N <= 100 | N >= 1;
  A <= B | A >= 0;
 
  cout << B - A << endl;
  
}