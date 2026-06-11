#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

void operator*=(vector< int > &latte, const vector< int > malta)
{
  for(int i = 0; i < malta.size(); i++) {
    latte[i] = malta[latte[i]];
  }
}

vector< int > mod_pow(vector< int > x, int64 n)
{
  vector< int > ret(x.size());
  iota(begin(ret), end(ret), 0);
  while(n > 0) {
    if(n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return (ret);
}

int main()
{
  int N, M, A[100000];
  int64 K, X[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i];
  }
  cin >> M >> K;
  for(int i = 0; i < M; i++) {
    cin >> A[i];
    --A[i];
  }

  int64 B[100000];
  vector< int > order(N - 1);
  iota(begin(order), end(order), 0);
  for(int i = 0; i < M; i++) {
    swap(order[A[i] - 1], order[A[i]]);
  }
  order = mod_pow(order, K);

  cout << X[0] << endl;
  auto base = X[0];
  for(int i = 0; i < N - 1; i++) {
    base += X[order[i] + 1] - X[order[i]];
    cout << base << endl;
  }
}