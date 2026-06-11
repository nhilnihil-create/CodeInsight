#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  ll N, A, B;
  cin >> N >> A >> B;

  bool ok = true;  
  if (A > B) ok = false;
  if (N == 1 && A != B) ok = false;

  if (!ok) {
    cout << 0 << endl;
    return 0;
  }

  ll minNum = (N - 1) * A + B;
  ll maxNum = A + (N - 1) * B;

  cout << maxNum - minNum + 1 << endl;
  
  return 0;
}