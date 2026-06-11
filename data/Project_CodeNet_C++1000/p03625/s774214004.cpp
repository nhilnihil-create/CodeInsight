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
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) 
  {
    cin >> A[i];
  }
  ll tate = 0;
  ll yoko = 0;
  ll ans = 0;
  sort(RALL(A));
  rep(i,N-3)
  {
    if(A[i]==A[i+1])
    {
      if(A[i]==A[i+2]&&A[i]==A[i+3]&&tate==0)
      {
        ans = A[i]*A[i];
        cout << ans << endl;
        return 0;
      }
      else if(tate==0)
      {
        tate = A[i];
        A[i+1] = -1;
        A[i] = -1;
      }
      else
      {
        yoko = A[i];
        ans = tate * yoko;
        cout << ans << endl;
        return 0;
      }
      
    }
  }
  if(yoko==0&&A[N-2]==A[N-1])
  {
    yoko = A[N-2];
    ans = tate * yoko;
    cout << ans << endl;
    return 0;
  }
  cout << 0 << endl;
  return 0;
}
