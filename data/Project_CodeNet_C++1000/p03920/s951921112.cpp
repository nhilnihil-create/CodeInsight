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
#define FINALANS(A) {cout << (A) << endl; exit(0);}

int main()
{
  ll N;
  cin >> N;

  vector<ll> A = {0};
  for (ll i = 1; ; i++)
  {
    if (A.back() >= N)
      break;
    A.push_back(A.back() + i);
  }

  ll x = distance(A.begin(), lower_bound(A.begin(), A.end(), N));
  cout << x << " " << endl;
  ll y = x * (x + 1) / 2 - N;
  //cerr << y << endl;
  for (ll i = x - 1; i >= 1; i--)
  {
    if (i != y)
      cout << i << endl;
  }
}