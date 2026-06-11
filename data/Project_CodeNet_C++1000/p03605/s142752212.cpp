#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A;
  cin >> N;
  
  A = N % 10;
  
  if(N >= 90){
    cout << "Yes" << endl;
  }
  else if(A == 9){
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
}