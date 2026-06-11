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
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  ll ans = 0;
  if(N==1)
  {
    ans += A[0] / 2;
  }
  rep(i,N-1)
  {
    if(A[i]+A[i+1]>=2)
    {
      ans += (A[i]+A[i+1])/2;
      if((A[i]+A[i+1])%2==0)
      {
        A[i] = 0;
        A[i+1] = 0;
      }
      else
      {
        if(A[i+1]>0)
        {
          A[i+1] = 1;
          A[i] = 0;
        }
        else
        {
          A[i+1] = 0;
          A[i] = 1;
        }
        
      }
    }
  }
  cout << ans << endl;
  return 0;
}
