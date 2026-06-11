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
  ll x,y;
  cin >> x >> y;
  if(y==x)
  {
    cout << 0 << endl;
  }
  else if(y==-x)
  {
    cout << 1 << endl;
  }
  else if(y==0&&x<0)
  {
    cout << y - x << endl;
  }
  else if(y==0&&x>0)
  {
    cout << x + 1 << endl;
  }
  else if(x==0&&y>0)
  {
    cout << y << endl;
  }
  else if(x==0&&y<0)
  {
    cout << 1 - y << endl;
  }
  else if(y>=0&&x<=0)
  {
    cout << abs(abs(x)-abs(y)) + 1 << endl;
  }
  else if(y<=0&&x>=0)
  {
    cout << abs(abs(x)-abs(y)) + 1 << endl;
  }
  else if(y>x&&x>0)
  {
    cout << y - x << endl;
  }
  else if(y>x&&y<0)
  {
    cout << y - x << endl;
  }
  else if(y<x&&y>0)
  {
    cout << x - y + 2 << endl;
  }
  else if(y<x&&x<0)
  {
    cout << x - y + 2 << endl;
  }
  return 0;
}
