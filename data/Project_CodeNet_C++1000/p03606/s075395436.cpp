#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N = 0;
  cin >> N;
  int T = 0;
  
  for (int i = 0; i < N; i++){
    
    int l = 0;
    int r = 0;
    
    cin >> l >> r;
    
    int dif;
    
    dif = r - l + 1;
    
    T = T + dif;
    
  }
  
  cout << T << endl;
  

 }