#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
typedef complex<double> cd;
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,w; cin >> h >> w;
  vector<int> cnt(26, 0);
  rep(i, h) {
    string s; cin >> s;
    for(auto&c:s) {
      ++cnt[c-'a'];
    }
  }

  priority_queue<int> pq;
  rep(i, 26) {
    pq.push(cnt[i]);
  }

  int need4 = (h&1 ? h - 1 : h) * (w&1 ? w - 1 : w);
  need4 /= 4;
  while(need4 > 0) {
    if(pq.empty() || pq.top() < 4) {
      cout << "No" << endl;
      return 0;
    }
    int topCnt = pq.top(); pq.pop();

    --need4;
    topCnt -= 4;
    if(topCnt) {
      pq.push(topCnt);
    }
  }

  int need2 = 0;
  if(h&1 && w&1) {
    need2 = (h + w - 2) / 2;
  } else if(h&1) {
    need2 = w / 2;
  } else if(w&1) {
    need2 = h / 2;
  }

  while(need2 > 0) {
    if(pq.empty() || pq.top() < 2) {
      cout << "No" << endl;
      return 0;
    }
    int topCnt = pq.top(); pq.pop();

    --need2;
    topCnt -= 2;
    if(topCnt) {
      pq.push(topCnt);
    }
  }

  cout << "Yes" << endl;
}
