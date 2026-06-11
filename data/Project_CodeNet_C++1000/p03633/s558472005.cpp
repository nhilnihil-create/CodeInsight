#include <cstdio>
#include <iostream>
#include <sstream>

#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <cassert>

#include <chrono>
#include <random>

using namespace std;
using i64 = int_fast64_t;
using ui64 = uint_fast64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<i64>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

//////////////////////////////////////////////////

i64 gcd(i64 l, i64 r){
  while(r){
    i64 t = r;
    r = l % r;
    l = t;
  }
  return l;
}

i64 lcm(i64 l, i64 r){
  return l / gcd(l, r) * r;
}

int main() { 
  int n;
  cin >> n;
  i64 t;
  cin >> t;
  for(int i=1;i<n;i++){
    i64 tt;
    cin >> tt;
    t = lcm(t, tt);
  }
  cout << t << endl;
  return 0;
}
