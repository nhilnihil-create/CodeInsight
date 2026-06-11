#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
#define ll int1024_t

// a C b
ll Combination(ll a,ll b) {
  ll ans = 1;
  for (ll i = a; i >= a - b + 1; i--) {
    ans *= i;
  }
  for (ll i = b; i >= 1; i--) {
    ans /= i;
  }
  return ans;
}

signed main() {
  int N,A,B;
  cin >> N >> A >> B;
  long long v[N];
  long double av = 0;
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v,v+N);
  reverse(v,v+N);
  for (int i = 0; i < A; i++) {
    av += v[i];
  }
  av /= A;
  cout << setprecision(120) << av << endl;
  bool all_same = true;
  for (int i = 0; i < A; i++) {
    if (v[0] != v[i]) {
      all_same = false;
    }
  }
  ll ans = 0;
  if (all_same) {
    int cnt = 0;
    for (int i = 0; i < N; i++)   {
      if (v[0] == v[i]) cnt++;
    }
    for (int i = A; i <= min(cnt,B); i++) {
      ans += Combination((ll)cnt,(ll)i);
    }
  } else {
    int cnt = 0;
    int num = 0;
    for (int i = 0; i < A; i++) {
      if (v[A-1] == v[i]) {
        cnt++;
      }
    }
    for (int i = 0; i < N; i++) {
      if (v[A-1] == v[i]) {
        num++;
      }
    }
    ans += Combination((ll)num,(ll)cnt);
  }
  cout << ans << endl;
}