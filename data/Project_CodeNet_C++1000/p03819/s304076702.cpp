#include<bits/stdc++.h>

using namespace std;

struct TPoint{
  int type;
  int id;
  int l;
  int r;
  int to;
};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<TPoint> queries;

  for(int i = 0; i < n; ++i) {
    int l, r; cin >> l >> r;
    queries.push_back({0, r, l, 0, 0});
  }

  vector<int> ans(m + 1);
  for(int i = 2; i <= m; ++i) {
    for(int p = 0; p <= m; p += i) {
      queries.push_back({1, p + i - 1, p, p + i - 1, i});
      queries.push_back({-1, p, p, p + i - 1, i});


    }
  }


  sort(queries.begin(), queries.end(), [&](TPoint u, TPoint v){
    return make_pair(u.id, abs(u.type)) < make_pair(v.id, abs(v.type));
  });

  vector<int> bit(m + m + 5, 0);

  for(auto &q : queries) {
    if(q.type == 0) {
      for(int x = q.l; x < bit.size(); x += x & -x) bit[x]++;
    }
    else {
      for(int x = q.r; x > 0; x -= x & -x) ans[q.to] += q.type * bit[x];
      for(int x = q.l; x > 0; x -= x & -x) ans[q.to] -= q.type * bit[x];
    }
  }

  for(int i = 1; i <= m; ++i) cout << n - ans[i] << "\n";

  return 0;
}
