#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i];
    if(i == SZ(s)-1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  int h, w, d; cin >> h >> w >> d;
  int n = max(h, w) * 3;
  vector<vector<int>> B = vector<vector<int>>(n, vector<int>(n));
  
  vector<int> colors = {1, 2, 3, 4};

  for(int i=0;i*d<n;++i) {
    for(int j=0;j*d<n;++j) {
      for(int a=0;a<d;++a) {
        for(int b=0;b<d;++b) {
          if(i * d + a < n && j * d + b < n) {
            B[i*d + a][j*d + b] = colors[i%2*2 + j%2];
          }
        }
      }
    }
  }

  auto ans = vector<vector<int>>(h, vector<int>(w));
  auto color = " RYGB";

  for(int i=0;i<h;++i) {
    for(int j=0;j<w;++j) {
      int ni = i + j;
      int nj = i - j + w;
      cout << color[B[ni][nj]];
    }
    cout << endl;
  }
}
