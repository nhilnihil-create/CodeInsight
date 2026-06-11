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

int c[9];
int main() {
  int n;
  cin >> n;
  rep(i,n){
    int a;
    cin >> a;
    a /= 400;
    c[min(a,8)]++;
  }
  int ans = 0;
  rep(i,8) if(c[i]>0) ++ans;
  cout << max(ans,1) << " " << ans+c[8] << endl;
}
