#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N,K;
  cin >> N >> K;
  int zero = 0;
  int total = 0;
  
  
  for (int i = 0; i < N; i++){
    int x;
    cin >> x;
    
    if (K - x <= x){
      total = total + (K -x) * 2;
    }
    else if (K - x > x){
      total = total + x * 2;
    }
    
  }
  
  cout << total << endl;

 }