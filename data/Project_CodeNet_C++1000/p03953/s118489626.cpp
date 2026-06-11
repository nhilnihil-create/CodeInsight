#include<bits/stdc++.h>
using namespace std;

using I = long long;

vector<I> E(auto N) {
  vector<I> R(N);
  iota(begin(R), end(R), 0);
  return R;
}

vector<I> mul(const auto& A, const auto& B) {
  vector<I> R(A.size());
  for(auto i=0; i<A.size(); ++i) R[i] = B[A[i]];
  return R;
}

vector<I> power(const auto& B, auto K) {
  if(K==0) return E(B.size());
  if(K&1) return mul(B, power(B, K - 1));
  return power(mul(B, B), K >> 1);
}

vector<I> solve(const auto& Y, const auto& B, auto K) {
  vector<I> X(Y.size());
  auto A = power(B, K);
  for(auto i=0; i<X.size(); ++i) X[i] = Y[A[i]];
  return X;
}

int main() {
  I N;
  cin >> N;
  vector<I> X(N);
  for(auto& i: X) cin >> i;
  I M, K;
  cin >> M >> K;
  vector<I> A(M);
  for(auto& i: A) cin >> i;

  vector<I> Y(N);
  Y[0] = X[0];
  for(auto i=1; i<N; ++i) Y[i] = X[i] - X[i-1];
  vector<I> B(N);
  iota(begin(B), end(B), 0);
  for(auto i: A) swap(B[i-1], B[i]);

  I ans = 0;
  for(auto i: solve(Y, B, K)) cout << (ans += i) << endl;
}
