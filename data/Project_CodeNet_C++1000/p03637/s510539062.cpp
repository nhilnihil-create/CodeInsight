#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  
  int multiple4 = 0, odd = 0, even = 0;
  
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    
    
    if (x % 4 == 0) {
      multiple4++;
    } else if (x % 2) {
      odd++;
    }
    
  }
  
  even = N - multiple4 - odd;
  if (even) {
    if (multiple4 >= odd) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    } 
  } else {
    if (multiple4 >= odd - 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
    
}