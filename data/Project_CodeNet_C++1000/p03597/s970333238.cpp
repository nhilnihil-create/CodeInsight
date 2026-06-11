#include <bits/stdc++.h>
using namespace std;

int main() {
  double N, A;
  cin >> N >> A;
  if( N < 1 ){ 
  	cout << "error: N under 1" << endl;
    return 1;
  }
  else if( N > 100 ){ 
  	cout << "error: N over 100" << endl;
    return 1;
  }
  if( A < 0 ){
  	cout << "error: A under 0" << endl;
    return 1;
  }
  else if( A > N*N){
  	cout << "error: A over N * N" << endl;
    return 1;
  }
  cout << (N*N) - A << endl;
}