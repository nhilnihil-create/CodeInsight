#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  if ( A + B >= 24 ){
    cout << (A + B - 24) <<endl;
  }
  else {
    cout << (A + B) << endl;
  }
}