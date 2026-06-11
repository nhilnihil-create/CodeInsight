#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const ll INF = 1e18;

int n,k;
int a[15];
int r[15];

ll cost(vector<int> &c) {
  ll s = 0;
  int p = r[c[0]];
  for(int i=0; i<c.size(); i++) {
    p = max(p, r[c[i]]);
    if(p >= a[c[i]]) {
      s += p - a[c[i]] + 1;
      p++;
    }
    else {
      p = a[c[i]];
    }
  }
  return s;
}

ll dfs(vector<int> &c, int index=0) {
  if(c.size() == k) return cost(c);
  int rest = n-index;
  if(c.size()+rest < k) return INF;
  ll s = INF;
  c.push_back(index);
  s = min(s, dfs(c, index+1));
  c.pop_back();
  s = min(s, dfs(c, index+1));
  return s;
}

signed main() {
  cin >> n >> k;
  rep(i,n) cin >> a[i];
  r[0] = 0;
  for(int i=1; i<n; i++) r[i] = max(r[i-1], a[i-1]);

  vector<int> c;
  c.reserve(n);
  cout << dfs(c) << endl;
}
