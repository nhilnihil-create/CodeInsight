#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//constexpr ll MOD = 1e9 + 7;
constexpr ll MOD = 998244353;
//constexpr ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
constexpr ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

int main()
{
  ll N;
  cin >> N;

  vector<ll> A(N);
  vector<ll> mp(N);
  for (ll i = 0; i < N; i++)
  {
    ll a;
    cin >> a;
    A.at(i) = a;
    mp.at(a)++;
  }

  ll Mx = *max_element(A.begin(), A.end());
  ll mn = *min_element(A.begin(), A.end());
  if (mp.at(mn) >= 3)
    FINALANS("Impossible");

  ll shouldMx = 2 * mn - (mp.at(mn) == 2);
  if (Mx != shouldMx)
    FINALANS("Impossible");
  
  for (ll i = mn + 1; i <= Mx; i++)
  {
    if (mp.at(i) < 2)
      FINALANS("Impossible");
  }
  FINALANS("Possible");
}