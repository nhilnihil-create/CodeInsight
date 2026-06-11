#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x, t;
  cin >>x >>t;
  
  if (x-t >= 0)
    cout << x - t;
  else
    cout << 0;
}