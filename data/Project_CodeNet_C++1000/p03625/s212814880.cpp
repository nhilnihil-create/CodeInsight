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
  map<int,int> m;
  vector<ll> d;
  rep(i,n){
    int a;
    cin >> a;
    m[a]++;
    if(m[a]==2)d.push_back(a);
    if(m[a]==4)d.push_back(a);
  }
  ll ans = 0;
  if(d.size()>=2){
    sort(d.rbegin(),d.rend());
    ans = d[0]*d[1];
  }
  cout << ans << endl;
}
