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
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;
const int MAX_H = 101;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  set<int> water, sugar;
  for(int i = 0; i <= 30; ++i) {
    for(int j = 0; j <= 30; ++j) {
      int amount = 100 * a * i + 100 * b * j;
      if(amount <= f) water.insert(amount);
    }
  }

  for (int i = 0; i <= 3000; ++i) {
    for(int j = 0; j <= 3000; ++j) {
      int amount = i * c + j * d;
      if(amount <= f) sugar.insert(amount);
    }
  }
  pair<int, int> ans;
  ans.first = a * 100;
  double maxper = 0;
  for (int w : water) {
    for (int s : sugar) {
      int sw = w + s;
      if(0 < sw && sw <= f) {
        if(s > (w / 100) * e) continue;
        double per = double(s) / sw;
        if(per > maxper) {
          maxper = per;
          ans.first = sw;
          ans.second = s;
        }
      }
    }
  }

  cout << ans.first << " " << ans.second << endl;;
}
