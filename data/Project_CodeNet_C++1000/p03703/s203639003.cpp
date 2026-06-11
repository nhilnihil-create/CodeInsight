#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct SetStk {
  vector<vector<LL>> stk;
  void add(LL x) {
    stk.push_back({x});
    while (stk.size() > 1) {
      int n = stk.size();
      if (stk[n - 1].size() == stk[n - 2].size()) {
        vector<LL> ans;
        merge(stk[n - 2].begin(), stk[n - 2].end(), 
              stk[n - 1].begin(), stk[n - 1].end(), back_inserter(ans));
        stk.pop_back();
        stk.back() = ans;
      }
      else break;
    }
  }
  int rank(LL a) {
    LL ans = 0;
    for (int i = 0; i < stk.size(); ++i) {
      auto &A = stk[i];
      ans += upper_bound(A.begin(), A.end(), a) - stk[i].begin();
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, k; cin >> n >> k;
  vector<LL> A(n + 1);
  for (int i = 0; i < n; ++i) cin >> A[i + 1], A[i + 1] -= k, A[i + 1] += A[i];
  SetStk ds;
  LL ans = 0;
  ds.add(A[0]);
  for (int i = 1; i <= n; ++i) {
    ans += ds.rank(A[i]);
    ds.add(A[i]);
  }
  cout << ans << '\n';
}  
