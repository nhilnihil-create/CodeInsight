#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, A, B, numA = 0, numB = 0;
  cin >> N >> A >> B;
  for(int i = 0; i < N; i++){
    cin >> A >> B;
    if(numA < A){
      numA = A;
      numB = B;
    }
  }
  cout << numA + numB << endl;
  return 0;
}