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
  int N,M;
  cin >> N >> M;
  if(abs(N-M)>1)
  {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  if((N+M)%2==0)
  {
    for(int i=1;i<N+1;i++)
    {
      ans *= i;
      ans %= P;
      ans *= i;
      ans %= P;
    }
    ans *= 2;
    ans %= P;
    cout << ans << endl;
  }
  else
  {
    if(M<N)
    {
      swap(M,N);
    }
    for(int i=1;i<N+1;i++)
    {
      ans *= i;
      ans %= P;
      ans *= i;
      ans %= P;
    }
    ans *= M;
    ans %= P;
    cout << ans << endl;
  }
  return 0;
}
