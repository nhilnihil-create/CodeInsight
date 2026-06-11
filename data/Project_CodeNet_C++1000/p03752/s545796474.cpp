#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

int main()
{
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  ll ans = INF;
  for (ll b = 0; b < (1LL << N); b++)
  {
    bitset<15> B = b;
    if (!B.test(0))
      continue;
    if (B.count() != K)
      continue;

    vector<ll> AA(N);
    for (ll i = 0; i < N; i++)
    {
      AA.at(i) = A.at(i);
    }

    ll mx = AA.front();
    ll tmp = 0;
    for (ll i = 1; i < N; i++)
    {
      if (B.test(i))
      {
        ll dh = max(0LL, mx + 1 - AA.at(i));
        tmp += dh;
        AA.at(i) += dh;
      }
      chmax(mx, AA.at(i));
    }
    chmin(ans, tmp);
  }
  cout << ans << endl;
}