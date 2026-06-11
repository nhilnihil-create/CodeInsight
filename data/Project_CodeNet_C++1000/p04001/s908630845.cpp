#include<iostream>
#include<string>
using namespace std;

int main() {
  string S; cin >> S;
  int N = S.size();
  long sum = 0;
  for (long p = (1<<(N-1)); p < (1<<N); p++) {
    long a = 0, b = 0;
    for (int i = 0; i < N; i++) {
      b = b * 10 + (S[i] - '0');
      if (p & (1<<i)) {
        a += b; b = 0;
      }
    }
    sum += a;
  }
  cout << sum << endl;
}