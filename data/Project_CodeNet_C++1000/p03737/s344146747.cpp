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
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  s1[0] -= 32;
  s2[0] -= 32;
  s3[0] -= 32;

  cout << s1[0] << s2[0] << s3[0] << endl;
  //<<  s2[0] + 32 << s3[0] + 32 << endl;
  return 0;
}
