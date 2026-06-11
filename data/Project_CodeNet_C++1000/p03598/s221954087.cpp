#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, x_i;
  int run_tot=0;
  
  cin >> N >> K;
  
  for (int i=0;i<N;i++){
    cin >> x_i;
    
    if ( x_i < K-x_i )
      run_tot += 2*x_i;
    else
      run_tot += 2*(K-x_i);
  }
  
  cout << run_tot << endl;
}