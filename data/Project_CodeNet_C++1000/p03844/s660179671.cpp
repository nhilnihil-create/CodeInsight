#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  char c;
  cin >> a >> c >> b;
  
  if(c == '+'){
    a += b;
  }
  else if(c == '-'){
    a -= b;
  }
  
  cout << a << endl;
}