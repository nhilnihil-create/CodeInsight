#include <bits/stdc++.h>
using namespace std;

long long func(vector<long long> &A, int cnt) {
  long long res = 0;
  for (int i = 0; i < cnt; i++) res += A.at(i);
  return res;
}

int main() {
  int N, W; cin >> N >> W;
  vector<long long> W1, W2, W3, W4;
  long long w1;
  for (int i = 0; i < N; i++) {
    int w, v; cin >> w >> v;
    if (i == 0) w1 = w;
    if (w == w1) W1.push_back(v);
    if (w == w1 + 1) W2.push_back(v);
    if (w == w1 + 2) W3.push_back(v);
    if (w == w1 + 3) W4.push_back(v);
  }
  sort(W1.begin(), W1.end(), greater<long long>());
  sort(W2.begin(), W2.end(), greater<long long>());
  sort(W3.begin(), W3.end(), greater<long long>());
  sort(W4.begin(), W4.end(), greater<long long>());
  int a = W1.size();
  int b = W2.size();
  int c = W3.size();
  int d = W4.size();
  long long ans = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int k = 0; k <= c; k++) {
        for (int l = 0; l <= d; l++) {
          long long weight = w1*i + (w1+1)*j + (w1+2)*k + (w1+3)*l;
          long long tmp = func(W1, i) + func(W2, j) + func(W3, k) + func(W4, l);
          if (weight <= W) ans = max(ans, tmp);
        }
      }
    }
  }
  cout << ans << endl;
}