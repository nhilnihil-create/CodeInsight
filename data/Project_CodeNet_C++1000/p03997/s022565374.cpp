#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int a, b, h; cin >> a >> b >> h;
  
  cout << (a+b)*h/2 << ((a+b)*h%2 == 1 ? ".5" : "") << endl; 
  return 0;
}