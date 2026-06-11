#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0)
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MAXR 100000

int main()
{
  int n; cin >> n;
  string s, t; cin >> s >> t;

  int cnt = n * 2;
  REP(i, n) {
    if (s[i] == t[0]) {
      if (i == n - 1) {
        cnt--;
        break;
      }
      int cont = 0;
      REP(j, n - i) {
        if (s[i + j] == t[j]) {
          cont++;
        }
      }
      if (cont == n - i) {
        cnt -= cont;
        break;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
