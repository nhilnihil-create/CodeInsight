#include <bits/stdc++.h>
using namespace std;

int digit(long long n){
  string s = to_string(n);
  return (int)s.size();
}

int main() {
  long long N;
  cin >> N;
  int ans = 1000000;
  
  for (long long A = 1; A < sqrt(N) + 10; A++){
    if (N % A) continue;
    long long B = N / A;
    ans = min(ans, max(digit(A), digit(B)));
  }
  
  cout << ans << endl;
}