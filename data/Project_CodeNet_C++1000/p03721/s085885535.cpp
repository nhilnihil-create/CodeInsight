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
  ll N,K;
  cin >> N >> K;
  vector<ll> a(N),b(N);
  rep(i,N) cin >> a[i] >> b[i];
  ll sum = 0;
  vector<pair<ll,ll>> vec(0);
  rep(i,N)
  {
    vec.push_back(make_pair(a[i],b[i]));
  }
  sort(ALL(vec));
  rep(i,N)
  {
    sum += vec[i].second;
    if(sum >= K)
    {
      cout << vec[i].first << endl;
      return 0;
    }
  }
  return 0;
}
