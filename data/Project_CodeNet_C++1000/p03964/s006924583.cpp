#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,t,a,n;
  cin >> N;
  int T[N], A[N];
  for (int i = 0; i < N; i++) {
    cin >> T[i] >> A[i];
  }
  t = T[0];
  a = A[0];
  n = 1;
  for (int i = 1; i < N; a=A[i], t = T[i++]) {
    n = max((t*n-1)/T[i]+1,(a*n-1)/A[i]+1);
  }
  cout << (a+t)*n;
}