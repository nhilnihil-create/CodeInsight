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
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  sort(ALLr(a));
  ll d[] = {0, 0};
  ll j = 0;
  REP(i, n-1){
    if(a[i] == a[i+1]){
      d[j] = a[i];
      j++;
      if(j == 2){
        cout << d[0]*d[1] << endl;
        return 0;
      }
      i++;
    }
  }
  cout << 0 << endl;
  return 0;
}