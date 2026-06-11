#include <bits/stdc++.h>
using namespace std;
  
int main() {
  string S;
  cin >> S;
  int N = S.size();
  int M = N;
  int countS = 0;
  int countT = 0;
  
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'S'){
      countS++;
    }
    if (S.at(i) == 'T' && countS > 0){
      M -= 2;
      countS--;
    }
  }
  cout << M << endl;
}
    
  