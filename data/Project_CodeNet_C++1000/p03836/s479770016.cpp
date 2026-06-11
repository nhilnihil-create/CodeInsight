#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define INF 1000000007
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
int main(){
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  string a(ty - sy,'U'),b(tx - sx,'R'),c(ty - sy,'D'),d(tx - sx,'L');
  cout << a << b << c << d;
  cout << "L";
  string e(ty - sy + 1,'U'),f(tx - sx + 1,'R'),g(ty - sy + 1,'D'),h(tx - sx + 1,'L');
  cout << e << f << "D" << "R" << g << h << "U" << endl;
  return 0;
}
