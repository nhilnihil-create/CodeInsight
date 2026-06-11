#include <iostream>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define rep(i,n) for(int i=0;i<(n);++i)

#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; cin >> N;

  int p[N];
  int a[N], b[N];
  int r[N];
  rep(i, N) {
    cin >> p[i];
    --p[i];
    r[p[i]] = i + 1;
  }
  rep(i, N) {
    a[i] = 30000 * (i+1);
    b[i] = 30000 * (N-(i+1)) + r[i];
  }
  rep(i, N) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << "\n";
  rep(i, N) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << "\n";

  return 0;
}
