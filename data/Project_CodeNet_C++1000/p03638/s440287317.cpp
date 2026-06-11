#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int inf = 1<<30;
const int mod = 1e9+7;

int main() {
  int H, W; cin >> H >> W;
  int N; cin >> N;
  vector<int> a(N);
  int ans[110][110];
  for(int i = 0; i < N; i++) cin >> a[i];
  int y = 0, x = 0;
  bool f = true;
  for(int i = 0; i < N; i++) {
    while(a[i]--) {
      if(f) {
        ans[y][x++] = i+1;
        if(x==W) {
          y++;
          x--;
          f = false;
        }
      } else {
        ans[y][x--] = i+1;
        if(x==-1) {
          y++;
          x++;
          f = true;
        }
      }
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(j) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
