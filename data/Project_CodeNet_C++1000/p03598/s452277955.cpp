#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N, K, Ans = 0, A = 0, B = 0, x = 0;//Nボール、K位置
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
      cin >> x;
      A = x*2;
      B = (K-x)*2;
        if (A < B) {
          Ans += A;
        }else{
          Ans += B;
        }
  }
  cout << Ans << endl;
}