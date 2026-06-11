#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  set <int> q;
  a[0] = 0;
  vector<int>ans(n,-1);
  ans[0]=0;
  vector<vector<int>>g(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin>>x;
    x--;
    g[x].push_back(i);
  }
  function<int(int)>solve=[&](int i){
    vector<int>cur;
    for (int j:g[i]){
      cur.push_back(solve(j));
    }
    int mx = 0;
    sort(cur.rbegin(),cur.rend());
    for (int i = 0; i < (int) cur.size(); i++) {
      mx = max(mx, cur[i] + i + 1);
    }
    return mx;
  };
  cout<<solve(0)<<endl;
}
