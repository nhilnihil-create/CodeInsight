#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = pow(10, 9) + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a >= b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << endl; exit(0);}

int main()
{
  ll N;
  cin >> N;
  vector<ll> T(N), A(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> T.at(i);
  }
  for (ll i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  vector<ll> H(N, -1);
  H.front() = T.front();
  for (ll i = 1; i < N; i++)
  {
    if (T.at(i - 1) != T.at(i))
      H.at(i) = T.at(i);
  }

  /*
  for (ll i = 0; i < N; i++)
  {
    cerr << H.at(i) << endl;
  }
  */

  if (H.back() != -1 && H.back() != A.back())
    FINALANS(0);
  H.back() = A.back();
  for (ll i = N - 2; i >= 0; i--)
  {
    if (H.at(i) != -1 && H.at(i) > A.at(i))
      FINALANS(0);
    if (A.at(i) != A.at(i + 1))
      H.at(i) = A.at(i);
  }

  /*
  for (ll i = 0; i < N; i++)
  {
    cerr << H.at(i) << endl;
  }
  */

  ll ans = 1;
  for (ll i = 0; i < N; i++)
  {
    if (H.at(i) == -1)
    {
      ans *= min(T.at(i), A.at(i));
      ans %= MOD;
    }
  }

  cout << ans << endl;
}