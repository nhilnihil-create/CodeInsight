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
  int n;
  cin >> n;
  ll l = 1, r = 1;
  rep(i,n){
    ll a,t;
    cin >> a >> t;
    ll m = max((l+a-1)/a,(r+t-1)/t);
    l = m*a, r = m*t; 
  }
  cout << l+r << endl;
}
