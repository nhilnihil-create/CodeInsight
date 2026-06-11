#include<bits/stdc++.h>

using namespace std;

#define reps(i, j, n) for(int i = j; i < (int)n; i++)
#define rep(i, n) reps(i, 0, n)

using int64 = long long;
const int mod = 1e9 + 7;

int64 calc(vector< int64 > &vs)
{
  int64 ret = 0;
  int64 less = 0;
  sort(begin(vs), end(vs));
  for(int i = 1; i < vs.size(); i++) {
    (less += vs[i - 1]) %= mod;
    (ret += vs[i] * i) %= mod;
    (ret += mod - less % mod) %= mod;
  }
  return (ret);
}

int main()
{
  int N, M;

  cin >> N >> M;
  vector< int64 > X(N), Y(M);
  rep(i, N) cin >> X[i];
  rep(i, M) cin >> Y[i];

  // ∑{i,j}∑{k,l} (x_i-x_j)*(y_k-y_l)
  // ∑{i,j} (x_i-x_j) * ∑{k,l} (y_k - y_l)
  // x_i - ∑(j<i) x_j

  cout << calc(X) * calc(Y) % mod << endl;
}

