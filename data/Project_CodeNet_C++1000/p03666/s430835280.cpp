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
#define FINALANS(A) {cout << (A) << '\n'; exit(0);}

int main()
{
  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  ll halfN = divceil(N, 2);
  vector<pair<ll, ll>> P(halfN);
  if (N % 2 == 1)
  {
    for (ll i = 0; i < halfN; i++)
    {
      P.at(i).first = C * (2 * i) + (C - D) * (halfN - i - 1);
      chmax(P.at(i).first, 0LL);
      P.at(i).second = D * (2 * i) + (D - C) * (halfN - i - 1);
    }
  }
  else
  {
    for (ll i = 0; i < halfN; i++)
    {
      P.at(i).first = C * (2 * i + 1) + (C - D) * (halfN - i - 1);
      chmax(P.at(i).first, 0LL);
      P.at(i).second = D * (2 * i + 1) + (D - C) * (halfN - i - 1);
    }
  }

  ll X = abs(A - B);
  for (ll i = 0; i < halfN; i++)
  {
    //cerr << P.at(i).first << " " << P.at(i).second << endl;
    if (P.at(i).first <= X && X <= P.at(i).second)
      FINALANS("YES");
  }
  FINALANS("NO");
}