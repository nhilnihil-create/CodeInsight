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
//typedef pair<int,int> P;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a,b,c,d;
  cin >> a >> b >> c >> c >> d;

  cout << max(a / 2 * 2 + b + c / 2 * 2 + d / 2 * 2,
              (a > 0 && c > 0 && d > 0 ? (a - 1) / 2 * 2 + b + (c - 1) / 2 * 2 + (d - 1) / 2 * 2 + 3 : 0LL)) << endl;

  return 0;
}
