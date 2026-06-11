#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  string S;
  cin >> S;
  int N = S.size();
  rep(i,N/2)
  {
    rep(j,2) S.pop_back();
    int n = S.size() / 2;
    if(S.substr(0,n)==S.substr(n,n))
    {
      cout << n * 2 << endl;
      return 0;
    }
  }
  return 0;
}
