#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

#define MAX_V 1000000
#define MAX_N 16
int n, k;
ll a[MAX_N], copy_a[MAX_N];

void input() {
  cin >> n >> k;
  rep(i, 0, n) cin >> a[i];
  memcpy(copy_a, a, sizeof(a));
}

bool validate(ll a[]) {
  int cnt = 1;
  ll max_v = a[0];
  rep(i, 1, n) {
    if(a[i] > max_v) {
      max_v = a[i];
      ++cnt;
    }
  }
  return cnt >= k;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

  input();

  ll rsl = 1e18;
  for(int bit = 0; bit < (1 << n); ++bit) {
    ll tmp = 0, max_v = copy_a[0];
    memcpy(copy_a, a, sizeof(a));
    for(int mask = 0; mask < n; ++mask) {
      if(bit & (1 << mask)) {
        if(mask == 0) continue;
        tmp += max(0ll, max_v - copy_a[mask] + 1);
        copy_a[mask] = max(max_v + 1, copy_a[mask]);
      }
      max_v = max(max_v, copy_a[mask]);
    }
    if(validate(copy_a)) {
      chmin(rsl, tmp);
    }
  }
  cout << rsl << endl;
}

