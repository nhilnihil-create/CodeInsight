#include <bits/stdc++.h>
using namespace std;

int main() {
  char c2;
  int x1,x3;
  cin >> x1 >> c2 >> x3;
  if (c2=='+'){
    cout << x1+x3 << endl;
  }else{
    cout << x1-x3 <<endl;
  }
  return 0;
}
