#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
const long long INF = 1LL << 60;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  ll A,B,C;
  cin >> A >> B >> C;
  if(A%2==1||B%2==1||C%2==1)
  {
    cout << 0 << endl;
    return 0;
  }
  if(A==B&&B==C)
  {
    cout << -1 << endl;
    return 0;
  }
  rep(i,10000)
  {
    if(A%4==2||B%4==2||C%4==2)
    {
      cout << i + 1 << endl;
      return 0;
    }
    else
    {
      ll a = A;
      ll b = B;
      ll c = C;
      A = b/2 + c/2;
      B = c/2 + a/2;
      C = a/2 + b/2;
    }
  }
  return 0;
}
