#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int a[2][200010];
int fnd(int k, int x) {
  return a[k][x] = (a[k][x] == x ? x : fnd(k, a[k][x]));
}
void uni(int k, int x, int y) {
  a[k][fnd(k, x)] = fnd(k, y);
}
map<int,int> mp[200010];
int main(){
  int n, k, l;
  cin >> n >> k >> l;
  iota(a[0], a[0] + n + 1, 0);
  iota(a[1], a[1] + n + 1, 0);
  for (int i = 0, p, q; i < k; i++) {
    cin >> p >> q;
    uni(0, p, q);
  }
  for (int i = 0, r, s; i < l; i++) {
    cin >> r >> s;
    uni(1, r, s);
  }
  for (int i = 1; i <= n; i++) {
    mp[fnd(0, i)][fnd(1, i)]++;
  }
  for (int i = 1; i <= n; i++) {
    cout << mp[fnd(0, i)][fnd(1, i)];
    if (i != n) cout << " ";
  }
  cout << endl;
  return 0;
}
