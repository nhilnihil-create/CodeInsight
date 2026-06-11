#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n; cin >> n;
  
  deque<int> memo;
  
  for (int i = 0; i < n; i++) {
    
    int a; cin >> a;
    
    if (i % 2 == 0) memo.push_back(a);
    
    if (i % 2 == 1) memo.push_front(a);
    
  }
  
  if (n % 2 == 0) {
    
    for (int i = 0; i < n; i++) {
      
      cout << memo.at(i);
      
      if (i != n - 1) cout << " ";
      
    }
    
  }
  
  if (n % 2 == 1) {
    
    for (int i = n - 1; 0 <= i; i--) {
      
      cout << memo.at(i);
      
      if (i != 0) cout << " ";
      
    }
    
  }
  
  cout << endl;
  
}