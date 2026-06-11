#include <bits/stdc++.h>
using namespace std;

int main () {
  long long A,B,C;
  cin >> A >> B >> C;
  long long cnt = 0;
  
  if (A%2==1 || B%2==1 || C%2==1) {   
    cout << 0 << endl;
    return 0;
  }
  
  if (A==B && B==C) {
    cout << -1 << endl;
    return 0;
  }
  
  while (true) {
    if (A%2==0 && B%2==0 && C%2==0) {   
      cnt++;
      long long a = B/2 + C/2;
      long long b = A/2 + C/2;
      long long c = A/2 + B/2;
      A = a;
      B = b;
      C = c;
    }
    else {
      cout << cnt << endl;
      break;
    }
  }
  
}