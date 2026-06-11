#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  long long T;
  cin >> n >> T;
  
  vector<long long> t(n);
  for ( int i = 0; i < n; i++){
    cin >> t[i];
  }
  
  long long goukei = 0;
  
  for ( int i = 0; i < n-1; i++){
    if ( t[i+1] - t[i] >= T ){
      goukei += T;
    }else{
      goukei += t[i+1] - t[i];
    }
  }
  
  goukei += T;
  
  cout << goukei << endl;  
  
}