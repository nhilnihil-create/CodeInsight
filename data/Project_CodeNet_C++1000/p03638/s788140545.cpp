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

int ans[100][100];
int main() {
  int h,w,n;
  cin >> h >> w >> n;
  int i = 0;
  rep(c,n){
    int a;
    cin >> a;
    rep(_,a){
      ans[i/w][i%w] = c+1;
      ++i;
    }
  }
  rep(i,h)rep(j,w) cout << ans[i][i%2==0?j:w-1-j] << (j==w-1?'\n':' ');
}