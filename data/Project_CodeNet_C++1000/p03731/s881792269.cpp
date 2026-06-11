#include <bits/stdc++.h>
using namespace std;

int main() {
  int N , T , Ans , Y , M ;
  cin >> N >> T ;
  
  M = 0;
  Y = 0;
  
  vector<int> vec(N);
  for (int i=0 ; i<N ; i++){
    cin >> vec.at(i) ; 
}
  for (int i=0 ; i<N-1 ; i++){
    int d = vec.at(i+1) - vec.at(i) ; 
    if (d >= T) M++ ;
    else Y = Y + d ;
  }
  // cout << T << endl << M << endl << Y << endl ;
  Ans = T + M*T + Y ;
  cout << Ans ; 
}