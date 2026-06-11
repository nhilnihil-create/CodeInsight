#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(a);i>(b);--i)
#define eper(i,a,b) for(int i=(a);i>=b;--i)
#define fore(x, a) for(auto &x : a)
#define pb push_back
#define mp make_pair
#define INF 100100100100
#define inf 2001001001
#define MOD 1000000007
#define ALL(x) begin(x),end(x)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vii = vector<int>;
using vll = vector<ll>;
template<class T>using vv = vector<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<class T>void show(const vector<T> &a) { for (int i = 0; i < (int)a.size(); ++i) cout << a[i] << (i != (int)a.size()-1 ? " " : "\n"); }
template<class T>T gcd(T a, T b){ return b ? gcd(b, a % b) : a; }
template<class T>T lcm(T a, T b){ return a / gcd(a, b) * b; }
int dy[]={0, 1, -1, 0};
int dx[]={1, 0, 0, -1};

int n;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
    cin >> n;
    vll t(n), a(n), mi(n, 0);
    rep(i, 0, n) cin >> t[i];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) mi[i] = min(t[i], a[i]);
    ll ans = 1;
    if (t[n-1] != a[0]) {
      cout << 0 << endl;
      return 0;
    }
    rep(i, 1, n-1) {
      if (t[i] == t[i-1] && a[i] == a[i+1]) {
        ans = (ans * mi[i]) % MOD;
      }
      else if (t[i-1] < t[i] && a[i] == a[i+1] && a[i] < t[i]) {
        ans = 0;
      } 
      else if (t[i-1] == t[i] && a[i] > a[i+1] && a[i] > t[i]) {
        ans = 0;
      }
      else if (t[i-1] > t[i] && a[i] < a[i+1] && a[i] != t[i]) {
        ans = 0;
      }
    }
    cout << ans << endl;
    return 0;
}

