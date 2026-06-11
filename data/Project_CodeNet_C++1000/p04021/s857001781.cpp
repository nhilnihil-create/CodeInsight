#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <deque>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  vector<pair<int, int> > p(n);

  rep(i, n) {
    cin >> a[i];
    p[i] = make_pair(a[i], i);
  }
  
  sort(p.begin(), p.end());

  int ans = 0;
  rep(i, n) {
    if ( p[i].second%2 != i%2 ) { ans++; }
  }

  cout << (ans+1)/2 << endl;

  return 0;
}