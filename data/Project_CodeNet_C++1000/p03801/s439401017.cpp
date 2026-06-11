#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N; cin >> N;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first; A[i].second = i;
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  A.push_back({0, -1});
  vector<ll> ans(N);
  for (int i = 0; i < N; i++) {
    A[i+1].second = min(A[i+1].second, A[i].second);
    ans[A[i].second] += ll(A[i].first - A[i+1].first) * (i+1);
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " \n"[i+1==N];
  }
}