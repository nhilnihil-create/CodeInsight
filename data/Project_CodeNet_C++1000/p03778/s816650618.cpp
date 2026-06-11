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
#define IN(p, a, b) a <= p && p <= b
using namespace std;

const int INF = 1001001001;

int main(void){
  int w, a, b;
  cin >> w >> a >> b;
  if(IN(b, a, a+w) || IN(b+w, a, a+w)){
    cout << 0 << endl;
    return 0;
  }
  cout << min(abs(a+w-b), abs(b+w-a)) << endl;
  return 0;
}