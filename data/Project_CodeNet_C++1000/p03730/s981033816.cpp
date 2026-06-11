#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  bool fin = false;
  
  for (int i = 1; i <= b; i++) {
    if (a*i%b == c) {
      cout << "YES";
      fin = true;
      break;
    }
  }
  
  if(!fin)
    cout << "NO";
      
}