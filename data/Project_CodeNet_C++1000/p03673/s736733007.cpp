#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,0,n-1) cin >> a[i];

  deque<int> b;
  if (n % 2 == 0) {
    rep(i,0,n-1) {
      i % 2 == 0 ? b.push_back(a[i]) : b.push_front(a[i]);
    } 
  } else {
    rep(i,0,n-1) {
      i % 2 == 0 ? b.push_front(a[i]) : b.push_back(a[i]);
    }
  }

  for (auto i : b) cout << i << ' ';
  return 0;
}
