#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N; cin >> N;
  string S; cin >> S;
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      vector<int> ans(N);
      ans[0] = a, ans[1] = b;
      for (int i = 1; i+1 < N; i++) {
        ans[i+1] = (S[i] == 'x') ^ ans[i] ^ ans[i-1];
      }
      if ((ans[0] ^ ans[1] ^ ans[N-1]) == (S[0] == 'x') && (ans[0] ^ ans[N-1] ^ ans[N-2]) == (S[N-1] == 'x')) {
        for (int i = 0; i < N; i++) {
          cout << "SW"[ans[i]];
        }
        cout << '\n';
        return 0;
      }
    }
  }
  cout << -1 << '\n';
}