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
#include <iomanip>

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
#define MAX_N 20
int n, k;
int a[MAX_N];
int tmpA[MAX_N];

void input() {
  cin >> n >> k;
  rep(i, 0, n) cin >> a[i];
}

void init() {
  rep(i, 0, n) tmpA[i] = a[i];
}

void solve() {
  ll rsl = 1e18;
  for(int bit = 0; bit < 1 << n; ++bit) {
    init();
    ll tmp = 0;
    int viewable = 1;
    int max_v = tmpA[0];
    rep(i, 1, n) {
      if(bit & (1 << i)) {
        if(tmpA[i] <= max_v) {
          tmp += max_v - tmpA[i] + 1;
          tmpA[i] = max_v + 1;
        }
        chmax(max_v, tmpA[i]);
        ++viewable;
      } else {
        if(tmpA[i] > max_v) {
          ++viewable;
          max_v = tmpA[i];
        }
      }
    }
    if(viewable >= k) chmin(rsl, tmp);
  }
  cout << rsl << endl;
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
  input();
  solve();
}
