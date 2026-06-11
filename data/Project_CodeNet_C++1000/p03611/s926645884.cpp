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

const int MAX = 1e5;
int main() {
  int n;
  cin >> n;
  vector<int> v(MAX);
  rep(i,n){
    int a;
    cin >> a;
    v[a]++;
  }
  int ans = 0;
  rep(i,MAX-2){
    ans = max(ans,v[i]+v[i+1]+v[i+2]);
  }
  cout << ans << endl;
}
