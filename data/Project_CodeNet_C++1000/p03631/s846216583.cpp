#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N ;
  
  if (N%101 < 100 && N%101%10 == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  
return 0;
}