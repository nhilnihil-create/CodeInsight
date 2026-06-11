#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = pow(10, 9) + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divCeil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << A << endl; exit(0);}

int main()
{
  ll N, x;
  cin >> N >> x;

  if (x == 1 || x == 2 * N - 1)
    FINALANS("No");

  vector<ll> ans(2 * N - 1);
  ans.at(N - 1) = x;
  ll y = (x <= N) ? (x - 1) : (x + 1);
  ans.at(N - 2) = y;
  for (ll i = 0, cnt = 1; i < 2 * N - 1; i++)
  {
    if (i == N - 1 || i == N - 2)
      continue;
    if (cnt == x || cnt == y)
      cnt++;
    if (cnt == x || cnt == y)
      cnt++;
    
    ans.at(i) = cnt;
    cnt++;
  }

  cout << "Yes" << endl;
  for (ll i = 0; i < 2 * N - 1; i++)
  {
    cout << ans.at(i) << endl;
  }
}