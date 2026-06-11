#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,K,x,Sum;
  cin >> N;
  cin >> K;
  Sum = 0;
  
  rep(i,N){
  cin >> x;
  if (x <= K/2)
    Sum += 2 * x;
  else
    Sum += 2 * (K-x);
  }
  cout << Sum << endl;
}
