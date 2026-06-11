#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  int a[N];
  rep(i,0,N-1) cin >> a[i];

  int ans = 0;
  rep(i,0,N-1) {
    int r = a[i]-1, l = a[r]-1;
    if (l == i) ans++;
  }

  cout << ans / 2 << endl;
  return 0;
}
