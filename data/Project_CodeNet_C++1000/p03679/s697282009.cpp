#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  if(z <= y){cout << "delicious" << endl;}
  else if (x+y >= z){cout << "safe" << endl;}
  else{cout << "dangerous" << endl;}
}