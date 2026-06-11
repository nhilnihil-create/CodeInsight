#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N;
  cin >> N;
  vector<long long int> A(N), B(N);
  for (long long int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
  
  long long int S = 0;
  for (long long int i = N - 1; i >= 0; i--) {
    A.at(i) += S;
    if (A.at(i) % B.at(i) != 0) S += (B.at(i) - (A.at(i) % B.at(i)));
  }
  
  cout << S << endl;
}