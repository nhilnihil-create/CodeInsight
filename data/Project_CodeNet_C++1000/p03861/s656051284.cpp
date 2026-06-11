#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B,X;
  cin >> A >> B >> X;
  if (!(A==0) && !(B==0)){
    cout << B/X-(A-1)/X << endl;
  }
  else if(A==0 && !(B==0)){
    cout << B/X+1 << endl;
  }
  else {
    cout << 1 << endl;
  }
}
