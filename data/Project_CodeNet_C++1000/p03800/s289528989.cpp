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
#define FINALANS(A) {cout << (A) << endl; exit(0);}

int main()
{
  ll N;
  cin >> N;
  string S;
  cin >> S;
  string ans = "";
  for (ll i = 0; i < N; i++)
  {
    ans += ' ';
  }

  vector<string> sw = {"SS", "SW", "WS", "WW"};
  for (ll q = 0; q < 4; q++)
  {
    ans.at(0) = sw.at(q).at(0);
    ans.at(1) = sw.at(q).at(1);
    for (ll i = 1; i < N - 1; i++)
    {
      bool b = (S.at(i) == 'o') ^ (ans.at(i - 1) == 'S') ^ (ans.at(i) == 'S');
      ans.at(i + 1) = b ? 'S' : 'W';
    }

    if (((S.at(N - 1) == 'o') ^ (ans.at(N - 1) == 'S')) != ((ans.at(N - 2) == 'S') ^ (ans.at(0) == 'S')))
      continue;
    if (((S.at(0) == 'o') ^ (ans.at(0) == 'S')) != ((ans.at(N - 1) == 'S') ^ (ans.at(1) == 'S')))
      continue;

    FINALANS(ans);
  }

  FINALANS(-1);
}