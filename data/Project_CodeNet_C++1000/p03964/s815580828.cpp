#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  Int N;
  cin >> N;
  
  vector<Int> tak(N, 1), aok(N, 1);
  
  
  rep(i,N) {
    Int T, A, gcd;
    cin >> T >> A;
    gcd = __gcd(T,A);
    T /= gcd;
    A /= gcd;
    if (i == 0) {
      tak[i] = T;
      aok[i] = A;
    }
    else {
      if (T >= tak[i-1] && A >= aok[i-1]) {
        tak[i] = T;
        aok[i] = A;
      }
      else {
        Int tq, aq, q;
        tq = (tak[i-1] + T - 1) / T;
        aq = (aok[i-1] + A - 1) / A;
        q = max(tq,aq);
        tak[i] = T * q;
        aok[i] = A * q;
      }
    }
  }
  
  cout << tak[N-1] + aok[N-1] << endl;
}