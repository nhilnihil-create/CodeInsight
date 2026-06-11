#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;  /* n*nのマス */
  int a;  /* 白に塗られたマス */
  
  // 
  // x = n^2 - a
  //
  
  cin >> n >> a;

  if (a > pow(n,2)) { 
    cout << "Error!" << endl;
  } else {
    cout << pow(n,2) - a << endl;
  }
}