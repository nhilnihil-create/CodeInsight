#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M;
int A[310][310];
set<int> st;

int rec() {
  if (st.size() == 0) return 1e18;

  int cnt[310] = {0};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (st.find(A[i][j]) != st.end()) {
        cnt[A[i][j]]++;
        break;
      }
    }
  }

  int mx = 0, er;
  for (int i = 0; i < M; i++) {
    if (mx < cnt[i]) {
      mx = cnt[i];
      er = i;
    }
  }

  st.erase(er);

  return min(mx, rec());
}

signed main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }

  for (int i = 0; i < M; i++) st.insert(i);

  cout << rec() << endl;
  return 0;
}
