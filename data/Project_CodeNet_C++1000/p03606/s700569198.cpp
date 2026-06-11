#include <bits/stdc++.h>
using namespace std;
 
int main() {
   int n;
   cin >> n;
   int y = 0;
   int c = 0;
  
  for (int i = 0; i < n; i++) {
   int a,b;
   cin >> a >> b;
   c = b-a+1;
   y = y + c;
}
  cout << y << endl;
  
}