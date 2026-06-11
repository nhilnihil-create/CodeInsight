#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << '\n'; exit(0);}

int main()
{
  ll N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<ll> A(N), B(N), C(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> A.at(i) >> B.at(i) >> C.at(i);
  }

  vector<vector<vector<ll>>> dp(44, vector<vector<ll>>(444, vector<ll>(444, INF)));
  dp.at(0).at(0).at(0) = 0;
  for (ll i = 0; i < N; i++)
  {
    for (ll a = 0; a < 404; a++)
    {
      for (ll b = 0; b < 404; b++)
      {
        chmin(dp.at(i + 1).at(a).at(b), dp.at(i).at(a).at(b));
        chmin(dp.at(i + 1).at(a + A.at(i)).at(b + B.at(i)), dp.at(i).at(a).at(b) + C.at(i));
      }
    }
  }

  ll ans = INF;
  for (ll i = 0; i <= N; i++)
  {
    for (ll k = 1; k <= 440 / max(Ma, Mb); k++)
    {
      ll tmp = dp.at(i).at(k * Ma).at(k * Mb);
      chmin(ans, tmp);
    }
  }
  cout << ((ans == INF) ? -1 : ans) << endl;
}