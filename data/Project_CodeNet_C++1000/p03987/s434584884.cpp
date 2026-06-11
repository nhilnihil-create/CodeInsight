#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (n); ++i)
#define rrep(i, j, n) for (int i = (n)-1; j <= i; --i)

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 2); // 前番兵、後番兵
  rep(i, 1, n + 1) cin >> a[i];
  // 蟻本 p298
  // 最大長方形、iを固定したときに
  // L[i] := a[j] < a[i]となるjのうち最も右のもの
  // R[i] := a[i] > a[j]となるjのうち最も左のもの
  // が入るようにする。これはstackでできる
  vector<ll> L(n + 2), R(n + 2);
  vector<ll> st;
  rep(i, 0, n + 1) {
    while (st.size() > 0 && a[st.back()] >= a[i]) st.pop_back();
    L[i] = st.size() > 0 ? st.back() + 1 : 0;
    st.push_back(i);
  }
  st.clear();
  rrep(i, 1, n + 2) {
    while (st.size() > 0 && a[st.back()] >= a[i]) st.pop_back();
    R[i] = st.size() > 0 ? st.back() : n + 1;
    st.push_back(i);
  }

  ll ans = 0;
  rep(i, 1, n + 1) ans += a[i] * (R[i] - i) * (i - L[i] + 1);

  cout << ans << endl;
  return 0;
}
