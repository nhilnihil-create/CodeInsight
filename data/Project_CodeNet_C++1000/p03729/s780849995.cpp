#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  string a, b, c;
  cin >> a >> b >> c;
  bool ok = true;
  if(*a.rbegin() != *b.begin()) ok = false;
  if(*b.rbegin() != *c.begin()) ok = false;


  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
