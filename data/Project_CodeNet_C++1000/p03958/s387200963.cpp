#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, int b) {
  if (a < b) a = b;
}

int main() {
  int K,T;
  cin >> K >> T;
  
  vector<int> cake(110, 0);
  
  for (int i = 0; i < T; i++) {
    cin >> cake[i];
  }
  
  int cakemax = 0;
  
  for (int i = 0; i < T; i++) {
    chmax(cakemax, cake[i]);
  }
  
  
  if (cakemax == K) {
    cout << K-1 << endl;
  } else if (cakemax * 2 > K) { 
    cout << cakemax * 2 - K - 1 << endl;
  } else {
    cout << 0 << endl;
  }
    
  
  
}