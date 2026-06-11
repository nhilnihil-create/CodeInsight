#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  int A=0;
  for (int i=0; i<N; i++){
    int X;
    cin >> X;
    if ( X < K-X ){
      A += 2*X;
    }else {
      A += 2*( K-X );
      
    }
  }
  cout << A << endl;
}