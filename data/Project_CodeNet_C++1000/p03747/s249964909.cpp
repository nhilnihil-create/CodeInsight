/**
 *    author:  tourist
 *    created: 06.01.2020 23:14:22       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long l, t;
  cin >> n >> l >> t;
  vector<long long> x(n);
  vector<long long> w(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> w[i];
  }
  vector<long long> finish(n);
  for (int i = 0; i < n; i++) {
    finish[i] = ((x[i] + (w[i] == 1 ? 1 : -1) * t) % l + l) % l;
  }
  long long me = finish[0];
  sort(finish.begin(), finish.end());
  if (w[0] == 1) {
    long long cnt = 0;
    for (int i = 1; i < n; i++) {
      if (w[i] == 2) {
        long long dist = x[i] - x[0];
        long long delta = 2 * t - dist - 1;
        if (delta >= 0) {
          cnt += delta / l + 1;
        }
      }
    }
    int who = (int) (cnt % n);
    int at = (int) (find(finish.begin(), finish.end(), me) - finish.begin());
    // I want finish[who] <- finish[at]
    // finish[0] <- finish[(at - who + n) % n]
    rotate(finish.begin(), finish.begin() + (at - who + n) % n, finish.end());
  } else {
    long long cnt = 0;
    for (int i = 1; i < n; i++) {
      if (w[i] == 1) {
        long long dist = (x[0] + l) - x[i];
        long long delta = 2 * t - dist;
        if (delta >= 0) {
          cnt += delta / l + 1;
        }
      }
    }
    int who = (n - (int) (cnt % n)) % n;
    int at = (int) (find(finish.begin(), finish.end(), me) - finish.begin());
    // I want finish[who] <- finish[at]
    // finish[0] <- finish[(at - who + n) % n]
    rotate(finish.begin(), finish.begin() + (at - who + n) % n, finish.end());
  }
  for (int i = 0; i < n; i++) {
    cout << finish[i] << '\n';
  }
  return 0;
}
