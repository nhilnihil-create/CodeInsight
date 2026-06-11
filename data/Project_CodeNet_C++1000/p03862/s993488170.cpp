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
  int n,x;
  cin >> n >> x;
  ll ans = 0;
  int p = 0;
  rep(i,n){
    int a;
    cin >> a;
    if(a>x) ans+=a-x, a=x;
    if(p+a>x) ans+=p+a-x, a=x-p;
    p=a;
  }
  cout << ans << endl;
}
