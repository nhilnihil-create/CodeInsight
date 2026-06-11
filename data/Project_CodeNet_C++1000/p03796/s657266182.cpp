#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a, pw=1;
  cin >> a ;
  for ( int64_t i =0 ; i<a ; i++){
    pw = (pw*(i+1))%(1000000007);
  }
  cout << pw << endl;
}