#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;

  int n=a*100,m=0;
  rep(ai,f/100/a+1)rep(bi,f/100/b+1){
    int ni = (a*ai+b*bi)*100;
    if(ni>f) continue;
    int x = min(f-ni,ni*e/100);
    rep(ci,x/c+1){
      int di = (x-c*ci)/d;
      int mi = c*ci+d*di;
      if(m*(ni+mi)<mi*(n+m)){
        n = ni;
        m = mi;
      }
    }
  }
  cout << (n+m) << " " << m << endl;
}
