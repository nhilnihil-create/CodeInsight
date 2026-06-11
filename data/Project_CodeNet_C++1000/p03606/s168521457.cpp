#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,sum = 0;
  cin >> N;
  vector<int> l(N),r(N);
  rep(i,N) cin >> l[i] >> r[i];
  rep(i,N) sum += (r[i] - l[i] + 1);
  cout << sum << endl;
}
