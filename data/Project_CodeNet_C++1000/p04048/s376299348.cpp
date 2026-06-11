#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
int myctoi(char C) {return C - 48;}
char myitoc(int N) {return '0' + N;}

signed main()
{
  int N, X;
  cin >> N >> X;
  
  int a = X, b = N - X;
  if (a > b) swap(a, b);
  int ans = N;
  cerr << a << " " << b << " " << ans << endl;
  while (a != 0 && b != 0)
  {
    if (b % a == 0) ans += -a + 2 * b;
    else ans += b / a * a * 2;
    b %= a;
    swap(a, b);
    cerr << a << " " << b << " " << ans << endl;
  }
  
  cout << ans << endl;
}