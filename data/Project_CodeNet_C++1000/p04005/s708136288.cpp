#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<ll> v(3);

int main() {
  cin >> v[0] >> v[1] >> v[2];
  if ((v[0]%2)*(v[1]%2)*(v[2]%2) == 0) {
    cout << 0 << endl;
  } else {
    sort(v.begin(), v.end());
    cout << v[0]*v[1] << endl;
  }
  return 0;
}
