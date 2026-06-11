#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
//constexpr ll MOD = 998244353;
//constexpr ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
constexpr ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

int main()
{
  ll H, W, h, w;
  cin >> H >> W >> h >> w;

  if (H % h == 0 && W % w == 0)
    FINALANS("No");

  bool swapped = false;
  if (W % w == 0)
  {
    swap(H, W), swap(h, w);
    swapped = true;
  }

  vector<vector<ll>> ans(H, vector<ll>(W));
  for (ll i = 0; i < H; i++)
  {
    ll a = 1e6;
    ll b = a * (w - 1) + 1;

    for (ll j = 0; j < W; j++)
    {
      ans.at(i).at(j) = ((j + 1) % w == 0) ? -b : a;
    }
  }

  cout << "Yes" << endl;
  if (swapped)
  {
    for (ll i = 0; i < W; i++)
    {
      for (ll j = 0; j < H; j++)
      {
        cout << ans.at(j).at(i) << ((j == H - 1) ? '\n' : ' ');
      }
    }
  }
  else
  {
    for (ll i = 0; i < H; i++)
    {
      for (ll j = 0; j < W; j++)
      {
        cout << ans.at(i).at(j) << ((j == W - 1) ? '\n' : ' ');
      }
    }
  }
}