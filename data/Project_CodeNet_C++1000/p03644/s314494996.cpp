#include<bits/stdc++.h>
using namespace std;

int main(){
  int a;
  cin >> a;
  if(a >= 64) cout << 64 << endl;
  else if(a >= 32) cout << 32 << endl;
  else if(a >= 16) cout << 16 << endl;
  else if(a >= 8) cout << 8 << endl;
  else if(a >= 4) cout << 4 << endl;
  else if(a >= 2) cout << 2 << endl;
  else cout << a << endl;
}