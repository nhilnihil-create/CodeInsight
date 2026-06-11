#include <bits/stdc++.h>

#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define vec vector<int>
#define dead not_bad

#define left not_right
#define y1 what

using namespace std;

const int N = (int) 3e5 + 10;
const int M = (int) 6e5 + 10;
const ll LINF = (ll) 2e18;
const int INF = (int) 1e9 + 7;
const int mod = 998244353;
const double PI = 3.14159265359;
const ld EPS = (ld) 1e-12;

int n;
string st, ans;
int dp[N];
int nxt[N][26], pre[26];

bool check(int i, int len) {  
  if (i == sz(st)) 
    return true;
  int val = dp[i] - 1;
  return val < len;
}

bool ok(int len) {
  ans = "";
  int ptr = 0;
  for (int i = 0; i < len; i++) {
    for (int alpha = 0; alpha < 26; alpha++) {
      if (check(nxt[ptr][alpha], len - 1 - i)) {
        ans += alpha + 'a';
        ptr = nxt[ptr][alpha];
        break;
      }
    } 
    if (sz(ans) != i + 1)
      return false;
  }
  return true;
}

int main() {
  #define fn "combination"
  #ifdef witch
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #else
     // freopen(fn".in", "r", stdin);
     // freopen(fn".out", "w", stdout);
  #endif
  srand(time(0));
  cin >> st;
  st = "#" + st;
  for (int j = 0; j < 26; j++) {
    pre[j] = nxt[sz(st)][j] = sz(st);
  }
  for (int i = sz(st) - 1; i >= 0; i--) {
    int val = INF;
    for (int j = 0; j < 26; j++) {
      val = min(val, dp[pre[j]]);
      nxt[i][j] = pre[j];
    }
    dp[i] = val + 1;
    pre[st[i] - 'a'] = i;
  }
  int l = 1, r = sz(st);
  int len;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      r = mid - 1;
      len = mid;
    } else {
      l = mid + 1;
    }
  }
 // cout << len << endl;
  ok(len);
  cout << ans;
  return 0;
}