#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-15;
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
const ll MOD1 = 998244353;
typedef pair<ll,ll> P;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define rrep(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,n) rep(i,0,n)
#define RREP(i,n) rrep(i,n,0)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll x;
  cin >> x;
  ll i = 0;
  while (1) {
    ll sum = i * (i + 1) / 2;
    if (sum >= x) {
      cout << i << endl;
      return 0;
    }
    i++;
  }

  return 0;
}
