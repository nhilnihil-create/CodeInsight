#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  string s;
  cin >> n >> s;
  
  int x = 0;
  vector<int64_t> A(n);
  
  for (int i = 0; i < n; i++) {
    
    if(s.at(i) == 'I'){
      x++;
    }
    else if(s.at(i) == 'D'){
      x--;
    }
    
    A.at(i) = x;
    
  }
  
  A.push_back(0);
  int64_t max = *max_element(A.begin(), A.end());
  cout << max << endl;

  
}
   