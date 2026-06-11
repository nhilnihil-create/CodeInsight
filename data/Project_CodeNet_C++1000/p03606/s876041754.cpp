#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin >> a;
  
  for (int i = 0; i < a; i++){
    cin >> b >> c;
    d += (c - b + 1) ;
  }
  cout << d << endl;
}



