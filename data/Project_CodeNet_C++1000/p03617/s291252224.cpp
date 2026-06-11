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
  ll Q,H,S,D,N;
  cin >> Q >> H >> S >> D >> N;
  ll sum = 0;
  if(2*Q<H)
  {
    H = 2*Q;
  }
  if(2*H<S)
  {
    S = 2*H;
  }
  if(2*S<D)
  {
    D = 2*S;
  }
  while(N>=2000)
  {
    N -= 2000;
    sum += D * 1000;
  }
  while(N>=2)
  {
    N -= 2;
    sum += D;
  }
  while(N>=1)
  {
    N -= 1;
    sum += S;
  }
  cout << sum << endl;
  return 0;
}
