#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll h, w;
  cin >> h >> w;
  ll ans = 1ll<<60;
  FOR(i, 1, h){
    ll d = h-i;
    ll a = w*i;

    ll b = (w+1)/2 * d;
    ll c = w/2 * d;
    ll mx = max(a, max(b, c));
    ll mn = min(a, min(b, c));
    chmin(ans, mx-mn);

    if(d < 2) continue;
    b = (d+1)/2 * w;
    c = d/2 * w;
    mx = max(a, max(b, c));
    mn = min(a, min(b, c));
    chmin(ans, mx-mn);
  }

  FOR(i, 1, w){
    ll d = w-i;
    ll a = h*i;

    ll b = (h+1)/2 * d;
    ll c = h/2 * d;
    ll mx = max(a, max(b, c));
    ll mn = min(a, min(b, c));
    chmin(ans, mx-mn);

    if(d < 2) continue;
    b = (d+1)/2 * h;
    c = d/2 * h;
    mx = max(a, max(b, c));
    mn = min(a, min(b, c));
    chmin(ans, mx-mn);
  }
  cout << ans << endl;
  return 0;
}