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
   
const int N = (int) 333;
const int M = (int) 100 + 11;
const ll LINF = (ll) 1e18;
const double PI = 3.14159265359;
const int INF = (int) 1e9 + 7;
const int mod = 1e9 + 7;
const double EPS = (double) 1e-9;

int n;
int a[N][N], nr[N][N];

int main() {
    #define fn "billboard"
    #ifdef witch  
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    //    freopen(fn".in", "r", stdin);
    //    freopen(fn".out", "w", stdout);
    #endif  
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (a[i][k] + a[k][j] < a[i][j]) {
            cout << -1;
            return 0;
          }
          if (i == k || j == k)
            continue;
          if (a[i][k] + a[k][j] == a[i][j]) {
            nr[i][j] = 1;
          }
        }
      }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (!nr[i][j])
          ans += a[i][j];
      }
    }
    cout << ans / 2;
    return 0;
} 