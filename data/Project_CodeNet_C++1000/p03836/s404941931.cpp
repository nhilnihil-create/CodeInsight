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
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  rep(i,ty-sy)
  {
    cout << "U";
  }
  rep(i,tx-sx)
  {
    cout << "R";
  }
  rep(i,ty-sy)
  {
    cout << "D";
  }
  rep(i,tx-sx)
  {
    cout << "L";
  }
  cout << "L";
  rep(i,ty-sy+1)
  {
    cout << "U";
  }
  rep(i,tx-sx+1)
  {
    cout << "R";
  }
  cout << "D";
  cout << "R";
  rep(i,ty-sy+1)
  {
    cout << "D";
  }
  rep(i,tx-sx+1)
  {
    cout << "L";
  }
  cout << "U" << endl;
  return 0;
}