#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  ll h, w;
  cin >> h >> w;
  ll ans = LLONG_MAX;
  rep(ni, 2) {
    for (int i = 1; i < h; ++i) {
      ll nh = h - i;
      ll area1 = i * w;
      ll area2 = (nh + 1) / 2 * w;
      ll area3 = (nh) / 2 * w;
      ll maxv = max(area1, max(area2, area3));
      ll minv = min(area1, min(area2, area3));
      ans = min(ans, maxv - minv);

      area2 = (w + 1) / 2 * nh;
      area3 = w / 2 * nh;
      maxv = max(area1, max(area2, area3));
      minv = min(area1, min(area2, area3));
      ans = min(ans, maxv - minv);
    }
    swap(h, w);
  }
  cout << ans << endl;

}
