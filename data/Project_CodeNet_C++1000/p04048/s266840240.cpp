#include<bits/stdc++.h>
using namespace std;
long long calc(long long N, long long X) {
  long long ans = N;
  if (X * 3 == N) return ans;
  N -= X;
  while (X) {
    long long u = N / X;
    long long v = N % X;
    ans += u * 2 * X;
    N = X;
    X = v;
  }
  return ans - N;
}
int main () {
  long long N, X;
  cin >> N >> X;
  cout << calc(N, X) << endl;
}

