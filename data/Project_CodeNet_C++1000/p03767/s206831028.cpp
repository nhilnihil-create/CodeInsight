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
  int N;
  cin >> N;
  ll sum = 0;
  vector<int> a(3*N);
  rep(i,3*N) cin >> a[i];
  sort(ALL(a));
  vector<int> s(N),m(3*N),l(3*N);
  rep(i,3*N)
  {
    if(i<N)
    {
      s[i] = a[i];
    }
    else
    {
      if((i-N)%2==0)
      {
        m[i] = a[i];
      }
      else
      {
        l[i] = a[i];
      }
      
    }
  }
  rep(i,3*N)
  {
    sum += m[i];
  }
  cout << sum << endl;
  return 0;
}
