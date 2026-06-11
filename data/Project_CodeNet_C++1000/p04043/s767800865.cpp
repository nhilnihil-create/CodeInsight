#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int ok_5 = 0;
  int ok_7 = 0;
  if(a == 5) ++ok_5;
  if(b == 5) ++ok_5;
  if(c == 5) ++ok_5;
  if(a == 7) ++ok_7;
  if(b == 7) ++ok_7;
  if(c == 7) ++ok_7;

  if(ok_5 == 2 && ok_7 == 1) cout << "YES" << endl;
  else cout << "NO" << endl;
  


  return 0;
}