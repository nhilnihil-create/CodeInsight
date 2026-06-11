#include<bits/stdc++.h>
using namespace std;
int ze(int a) {
  if (a < 0) return -a;
  return a;
}
int main () {
  int N;
  cin >> N;
  vector<int>A(N);
  for (int i = 0; i < N; i ++) cin >> A[i];
  int sum = 0;
  for (int i = 0; i < N; i ++) sum += A[i];
  int ko = sum / N;
  int ko_ = ko + 1;
  if (sum < 0) ko_ = ko - 1;
  if (ze(ko * N - sum) > ze(ko_ * N - sum)) ko = ko_;
  int ans = 0;
  for (int i = 0; i < N; i ++) {
    ans += (A[i] - ko) * (A[i] - ko);
  }
  cout << ans << endl;
}