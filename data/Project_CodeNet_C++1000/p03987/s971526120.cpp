#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), idx(n+1);
  rep(i,n) cin >> a[i], idx[a[i]] = i + 1;

  ll res = 0;

  set<int> st;
  st.insert(0);
  st.insert(n+1);

  for (int a = 1; a <= n; a++) {
    auto itr = st.upper_bound(idx[a]);
    int r = *itr;
    int l = *(--itr);
    res += ll(a) * (idx[a] - l) * (r - idx[a]);
    st.insert(idx[a]);
  } 
  cout << res << endl;
  return 0;
} 