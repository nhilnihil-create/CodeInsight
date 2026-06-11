#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
 
#define y1 what

using namespace std;
 
const int N = (int) 1e5 + 10;
const int M = (int) 101;
const ll big =  (1LL << 51);
const ll LINF = (ll) 1e18;
const int INF = (int) 1e9 + 7;
const int INF1 = (int) 1e9 + 3;
const double EPS = (double) 1e-6;
const double PI =  3.14159265359;

int n;
vector<int> a;

int calc(vector<int> v) {
  bool ok = 1;
  for (auto it : v) {
    ok &= it == 1;
  }
  if (ok) {
    return 0;
  }
  int cnt_even = 0;
  for (auto it : v) {
    cnt_even += 1 - it % 2;
  }
  if (cnt_even % 2) {
    return 1;
  } 
  if (sz(v) - cnt_even > 1) {
    return 0;
  }
  int gcd = 0;
  vector<int> g = v;
  for (auto &it : g) {
    it -= it % 2;
    if (!it)
      return 0;
    gcd = __gcd(gcd, it);
  }
  for (auto &it : g) {
    it /= gcd;
  }
  return !calc(g);
} 


int main() {
    #define fn "balls"
    #ifdef witch
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
//        freopen(fn".in", "r", stdin);
//        freopen(fn".out", "w", stdout);
    #endif
    srand(time(0));
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << (calc(a) ? "First" : "Second");
    return 0;
}