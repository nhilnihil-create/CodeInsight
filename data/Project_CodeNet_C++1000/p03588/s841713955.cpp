#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<long long> B(N);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  sort(A.begin(), A.end()); 
  sort(B.begin(), B.end()); 
  cout << A.at(N-1) + B.at(0);
}
