#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> a(N), b(N), c(M), d(M);

  for(int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }

  for(int i = 0; i < M; i++) {
    cin >> c[i] >> d[i];
  }

  for(int i = 0; i < N; i++) {
    ll min_d = 1000000000000;
    int index = 0;
    ll s = 0;
    for(int j = 0; j < M; j++) {
      s = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if(min_d > s) { min_d = s; index = j; }
    }
    cout << index + 1 << endl;
  }
  return 0;
}