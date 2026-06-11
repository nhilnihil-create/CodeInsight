#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, M;
  cin >> N >> M;
  if (M >= 2*N) {
    cout << N+(M-2*N)/4;
  } else {
    cout << M/2;
  }
}