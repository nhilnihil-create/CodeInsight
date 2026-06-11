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
  ll I, O, T, J, L, S, Z;
  cin >> I >> O >> T >> J >> L >> S >> Z;

  ll K0 = O, K1 = O;

  K0 += I / 2 * 2 + J / 2 * 2 + L / 2 * 2;
  if (I % 2 == 1 && J / 2 == 1 && L / 2 == 1)
    K0 += 3;

  if (I >= 1 && J >= 1 && L >= 1)
    K1 += 3;
  K1 += max(0LL, I - 1) / 2 * 2 + max(0LL, J - 1) / 2 * 2 + max(0LL, L - 1) / 2 * 2;

  cout << max(K0, K1) << endl;
}