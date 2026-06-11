#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,A,B;
  cin >> N >> A >> B;
  if(A>B){
    cout << 0 << endl;
    return 0;
  }
  if(N == 1 && A-B != 0){
    cout << 0 << endl;
    return 0;
  }
  if(N == 1){
    cout << 1 << endl;
    return 0;
  }
  cout << (N-1)*(B-A)+A-B+1 << endl;
    
}
