#include <bits/stdc++.h>
using namespace std;

#define rep(i,j,n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(), i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9 + 7;

typedef long long i64;
typedef pair<int, int> pi;

template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;

i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcd(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W, h, w;
  cin >> H >> W >> h >> w;

  vvt<int> vec(H, vt<int>(W, 1000));
  rep(i, 1, H + 1) {
    rep(j, 1, W + 1) {
      if(i % h == 0 && j % w == 0) vec[i - 1][j - 1] = -1000 * (h * w - 1) - 1;
    }
  }

  int sum = 0;
  rep(i, 0, H) rep(j, 0, W) sum += vec[i][j];
  if(sum <= 0) return cout << "No\n", 0;

  cout << "Yes\n";
  rep(i, 0, H) {
    cout << vec[i][0];
    rep(j, 1, W) cout << " " << vec[i][j];
    cout << endl;
  }
}