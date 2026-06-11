#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[3] ;
  int _5 = 0 , _7 = 0 ;
  for (auto &X : arr) {
    cin >> X ;
    if (X == 5 ) _5++ ;
    if (X == 7 ) _7++ ;
  }
  if (_5 == 2 && _7 == 1)cout << "YES" << endl ;
  else cout << "NO" << endl ;
  return 0 ;
}