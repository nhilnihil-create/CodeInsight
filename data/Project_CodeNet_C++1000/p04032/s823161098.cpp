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
  string s;
  cin >> s;
  ll n = s.size();
  REP(i, n-1){
    if(s[i] == s[i+1]){
      printf("%lld %lld\n", i+1, i+2);
      return 0;
    }
    if(i+2 < n && s[i] == s[i+2]){
      printf("%lld %lld\n", i+1, i+3);
      return 0;
    }
  }
  cout << "-1 -1" << endl;
  return 0;
}