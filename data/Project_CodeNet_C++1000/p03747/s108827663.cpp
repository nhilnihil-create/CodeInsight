#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int N, L, T;
  vector<int> X, W;
  
  cin >> N >> L >> T;
  X.resize(N);
  W.resize(N);
  for (int i = 0; i < N; i++) cin >> X[i] >> W[i];
  
  vector<int> tmp(N);
  for (int i = 0; i < N; i++) {
    if (W[i] == 1) tmp[i] = (X[i] + T) % L;
    else tmp[i] = ((X[i] - T) % L + L) % L;
  }
  
  sort(tmp.begin(), tmp.end());
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (W[i] == 1) count -= (T - (L - X[i]) + L) / L;
    else count += (T- (X[i]+1) + L) / L;
  }
  
  count = (count % N + N) % N;
  vector<int> res(N);
  for(int i = 0; i < N; i++) res[(i+count)%N] = tmp[i];
  for(int i = 0; i < N; i++) cout << res[i] << endl;
}