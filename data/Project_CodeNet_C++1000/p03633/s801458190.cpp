#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
ll gcd(ll a, ll b) { return b != 0 ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  ll N;
  cin >> N;
  vector<ll> T(N);
  rep(i,N)
  {
    cin >> T[i];
  }
  ll M = 1;
  rep(i,N)
  {
    M = max(M,lcm(M,T[i]));
  }
  cout << M << endl;
  return 0;
}
