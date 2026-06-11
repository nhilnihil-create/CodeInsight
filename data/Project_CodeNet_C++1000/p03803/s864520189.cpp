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
  int a, b;
  cin >> a >> b;
  if(a == 1) a = 14;
  if(b == 1) b = 14;
  if(a>b) cout << "Alice" << endl;
  else if(a == b) cout << "Draw" << endl;
  else cout << "Bob" << endl;
  return 0;
}
