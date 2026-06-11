#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  int N,L,T;
  cin >> N >> L >> T;

  vector<int> X(N),W(N),X2(N);
  int count = 0;

  for(int i=0; i<N; i++) {
    cin >> X[i] >> W[i];
    if (W[i] == 1) count -= (T + X[i]) / L;
    else           count += (T - (X[i]+1-L)) / L;
    if (W[i] == 1) X2[i] = (X[i] + T) % L;
    else X2[i] = ((X[i] - T) % L + L) % L;
  }
  count = (count % N + N) % N;
  sort(X2.begin(), X2.end());
  for(int i=0; i<N; i++) cout << X2[(i - count + N) % N] << endl;
  return 0;
}
