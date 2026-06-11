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

int inf = 10001;
int main() {
  int n;
  cin >> n;
  vector<bool> v(inf);
  v[0] = true;
  rep(_,n){
    int s;
    cin >> s;
    vector<bool> v2 = v;
    rep(i,inf-s) if(v[i]) v2[i+s] = true;
    v = v2;
  }
  int ans = 0;
  rep(i,inf) if(v[i]&&i%10>0) ans = i;
  cout << ans << endl;
}
