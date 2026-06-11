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
  int W,H,N;
  cin >> W >> H >> N;
  vector<int> x(N),y(N),a(N);
  rep(i,N) cin >> x[i] >> y[i] >> a[i];
  int lx = 0;
  int rx = W;
  int ly = 0;
  int ry = H;
  rep(i,N)
  {
    if(a[i]==1) lx = max(x[i],lx);
    else if(a[i]==2) rx = min(x[i],rx);
    else if(a[i]==3) ly = max(y[i],ly);
    else ry = min(y[i],ry);
  }
  int yoko = rx - lx;
  int tate = ry - ly;
  if(yoko<=0||tate<=0)
  {
    cout << 0 << endl;
    return 0;
  }
  cout << tate*yoko << endl;
  return 0;
}
