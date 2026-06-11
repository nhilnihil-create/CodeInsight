#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  long N = S.size();
  map<char, long> MA;
  for (long i = 0; i < N; i++) {
    MA[S.at(i)]++;
  }
  long ans = 0;
  for (long i = 0; i < N; i++) {
    ans += N - MA[S.at(i)];
  }
  cout << ans / 2 + 1 << "\n";  
}