#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int W, a, b;
  cin >> W >> a >> b;

  if (abs(b - a) < W) cout << 0 << endl;
  else cout << abs(b - a) - W << endl;
}
