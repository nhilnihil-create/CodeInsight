#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  set<int> st;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i % 2 == 0) st.insert(A[i]);
  }
  vector<int> B = A;
  sort(B.begin(), B.end());
  int res = 0;
  for (int i = 1; i < N; i += 2) {
    if (st.find(B[i]) != st.end()) res++;
  }
  cout << res << '\n';
  return 0;
}
