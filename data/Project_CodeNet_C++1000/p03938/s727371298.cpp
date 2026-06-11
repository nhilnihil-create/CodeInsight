#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; cin >> N;

  int a[N], b[N];
  int r[N];
  rep(i, N) {
    int p; cin >> p;
    r[p-1] = i + 1;
  }
  rep(i, N) {
    if (i) cout << " ";
    cout << 30000 * (i+1);
  }
  cout << "\n";
  rep(i, N) {
    if (i) cout << " ";
    cout << 30000 * (N-(i+1)) + r[i];
  }
  cout << "\n";

  return 0;
}
