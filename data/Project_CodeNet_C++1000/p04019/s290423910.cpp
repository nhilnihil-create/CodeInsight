#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int cnt_N = 0, cnt_W = 0, cnt_S = 0, cnt_E = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'N') cnt_N++;
    else if (S[i] == 'W') cnt_W++;
    else if (S[i] == 'S') cnt_S++;
    else cnt_E++;
  }
  bool can = true;
  if (cnt_N == 0 || cnt_S == 0) {
    if (!(cnt_N == 0 && cnt_S == 0)) can = false;
  }
  if (cnt_W == 0 || cnt_E == 0) {
    if (!(cnt_W == 0 && cnt_E == 0)) can = false;
  }
  if (can) cout << "Yes";
  else cout << "No";
}
