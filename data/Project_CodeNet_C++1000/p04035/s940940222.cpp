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
  int N,L;
  cin >> N >> L;
  vector<int> a(N),b(N);
  rep(i,N) 
  {
    cin >> a[i];
  }
  rep(i,N-1)
  {
    b[i] = a[i] + a[i+1];
  }
  sort(RALL(b));
  if(b[0]<L)
  {
    cout << "Impossible" << endl;
    return 0;
  }
  else
  {
    cout << "Possible" << endl;
    int k = 0;
    rep(i,N-1)
    {
      if(a[i]+a[i+1]==b[0])
      {
        k = i+1;
        break;
      }
      else
      {
        cout << i + 1 << endl;
      }
    }
    for(int i = N-1;i>=k;i--)
    {
      cout << i << endl;
    }
  }
  return 0;
}
