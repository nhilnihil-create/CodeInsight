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
  ll N;
  cin >> N;
  ll count = 0;
  vector<ll> A(N),B(N);
  rep(i,N) cin >> A[i] >> B[i];
  for(int i=N-1;i>-1;i--)
  {
    A[i] += count;
    if(A[i]%B[i]!=0)
    {
      count += B[i] - A[i]%B[i];
    }
  }
  cout << count << endl;
  return 0;
}
