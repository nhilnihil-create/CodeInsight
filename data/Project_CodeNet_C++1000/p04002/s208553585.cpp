#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INT_INF 1000000000
#define DOUBLE_INF 1e18
#define MOD 1000000007
#define mod(x) ((x % MOD) + MOD) % MOD
#define MAX_N 100001

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main()
{
  int H, W, N, A[MAX_N], B[MAX_N];
  cin >> H >> W >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }

  map<P, ll> count;
  for (int i = 0; i < N; i++) {
    int x = A[i], y = B[i];
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (1 <= x+dx && x+dx <= H-2 &&
            1 <= y+dy && y+dy <= W-2) {
          count[P(x+dx, y+dy)]++;
        }
      }
    }
  }
  map<int, ll> ans;
  ans[0] = (ll)(H-2) * (ll)(W-2);
  for (auto itr = count.begin(); itr != count.end(); ++itr) {
    ans[itr->second]++;
  }

  ll sum = 0;
  for (int i = 1; i < 10; ++i) {
    sum += ans[i];
  }
  ans[0] -= sum;

  for (int i = 0; i < 10; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
