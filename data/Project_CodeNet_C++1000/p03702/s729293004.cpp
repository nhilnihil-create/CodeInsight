#include <iostream>
#include <vector>

#define ll long long
#define INF 1 << 40

using namespace std;

ll N, A, B;
vector<ll> h(100100);

bool check(ll n) {
  ll count = n;
  for (int i = 0; i < N; i++) {
    ll rem = max(h[i] - n * B, 0LL);
    if (rem % (A - B) == 0)
      count = count - (rem / (A - B));
    else
      count = count - (rem / (A - B) + 1);
  }
  if (count >= 0) {
    return true;
  }
  return false;
}

int main() {
  cin >> N >> A >> B;
  ll mx = -1;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
    mx = max(mx, h[i]);
  }

  ll ok = mx / B + 1, ng = 0;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
}