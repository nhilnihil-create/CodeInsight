#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K, S, A, B;
  cin >> N >> K;
  S = 0;
  A = 0;
  B = 0;
  for(int i = 0;i < N;i++){
    int x;
    cin >> x;
    A = 2 * x;
    B = (x - K) * 2;
    if(B < 0)
      B *= -1;
   if(A > B){
     S += B;
   }
   else{
     S += A;
  }
  }
  cout << S << endl;
}