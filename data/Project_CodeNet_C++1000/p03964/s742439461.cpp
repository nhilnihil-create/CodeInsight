#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  vector<long long> T(N);
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> T[i] >> A[i];
  }

  vector<long long> t(N);
  vector<long long> a(N);

  t[0] = T[0];
  a[0] = A[0];

  for (int i = 1; i < N; i++) {

    long long t_ = t[i - 1] / T[i];
    
    if (t[i - 1] % T[i] != 0) {
      t_++;
    }
    
    long long a_ = a[i - 1] / A[i];
    
    if (a[i - 1] % A[i] != 0) {
      a_++;
    }
    
    long long n = max(t_, a_);
    
    t[i] = n * T[i];
    a[i] = n * A[i];
    
  }

  cout << t[N - 1] + a[N - 1] << endl;
  
  return 0;

}