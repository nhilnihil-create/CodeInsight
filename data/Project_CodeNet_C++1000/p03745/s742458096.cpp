#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int N, prev, ans = 1, now;
  bool status = true;
  cin >> N;
  if (N <= 2) {
    cout << ans << endl;
    return 0;
  }

  N -= 2;
  cin >> prev >> now;
  while (prev == now) {
    cin >> now;
    N--;
  }
  if (prev > now) status = false;
  prev = now;

  while (N) {
    cin >> now;
   // cout << prev << " " << now << " " << status << endl;
    N--;
    if (prev == now) continue;
    if (status && prev > now) {
      ans++;
      prev = now;
      if (N <= 1) break;
      while (N && prev == now) {
        cin >> now;
        N--;
      }
      if (prev > now) status = false;
      prev = now;
      continue;
    } else if (!status && prev < now) {
      ans++;
      prev = now;
      if (N <= 1) break;
      while (N && prev == now) {
        cin >> now;
        N--;
      }
      if (prev < now) status = true;
      prev = now;
      continue;
    }
    prev = now;
  }

  cout << ans << endl;
}