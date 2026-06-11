#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

// 最大公約数
ll gcd(ll m, ll n) {
  if (n==0) return abs(m);
  else return gcd(n, m%n);
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  ll g = A[0];
  for (int i=1; i<N; i++) g = gcd(g, A[i]);
  if (K%g!=0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  if (K>*max_element(A.begin(), A.end())) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << "POSSIBLE" << endl;
  return 0;
}