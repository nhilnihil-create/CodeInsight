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
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << A << endl; exit(0);}

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  ll S = accumulate(A.begin(), A.end(), 0LL);
  if (S % (N * (N + 1) / 2) != 0)
    FINALANS("NO");
  ll K = S / (N * (N + 1) / 2);

  ll M = 0;
  for (ll i = 0; i < N; i++)
  {
    ll D = A.at((i + 1) % N) - A.at(i) - K;
    if (D > 0)
      FINALANS("NO");
    if (-D % N != 0)
      FINALANS("NO");
    M += -D / N;
  }
  cout << ((M == K) ? "YES" : "NO") << endl;
}