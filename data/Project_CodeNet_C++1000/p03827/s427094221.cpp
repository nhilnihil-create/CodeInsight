#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x = 0;
  int n;
  string s;
  
  cin >> n >> s;
  
  int max = x;
  
  for (char c : s) {
    if (c == 'I')
      x++;
    else
      x--;
    
    if (max < x)
      max = x;
  }
  
  cout << max;
  
}