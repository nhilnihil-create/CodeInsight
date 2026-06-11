#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define print(x) cout << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T> >
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

int main() {
  int n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll ans = 1LL << 60, sum = a[0];
  ll tmp = 0;

  if(a[0] < 0){
    tmp = abs(a[0])+1;
    sum = 1;
  }

  if(sum == 0){
    tmp++;
    sum++;
  }
  
  srep(i, 1, n) {
    sum += a[i];
    if (sum == 0) {
      tmp++;
      if (sum - a[i] > 0)
        sum--;
      else
        sum++;
    }
    if (sum - a[i] >= 0 && sum >= 0) {
      tmp += sum + 1;
      sum = -1;
    } else if (sum - a[i] <= 0 && sum <= 0) {
      tmp += abs(sum) + 1;
      sum = 1;
    }
  }
  mins(ans, tmp);
  tmp = 0;
  sum = a[0];
  if(a[0] > 0){
    tmp = a[0]+1;
    sum = -1;
  }
  if(sum == 0){
    tmp++;
    sum--;
  }
  srep(i, 1, n) {
    sum += a[i];
    if (sum == 0) {
      tmp++;
      if (sum - a[i] > 0)
        sum--;
      else
        sum++;
    }
    if (sum - a[i] >= 0 && sum >= 0) {
      tmp += sum + 1;
      sum = -1;
    } else if (sum - a[i] <= 0 && sum <= 0) {
      tmp += abs(sum) + 1;
      sum = 1;
    }
  }
  mins(ans, tmp);
  print(ans);
  return 0;
}