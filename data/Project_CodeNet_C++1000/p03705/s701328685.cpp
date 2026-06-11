#include <bits/stdc++.h>
using namespace std;

int main () {
  long long N,A,B;
  cin >> N >> A >> B;
  
  if (A > B){
    cout << 0 << endl;
    return 0;
  }
  if (A != B && N == 1){
    cout << 0 << endl;
    return 0;
  }
  long long M = (B-A)*(N-2) + 1;
  cout << M << endl;
}
  