#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<ll, ll> pll;

int n;
int l[100005];

bool can(int numC) {
  // is it possible that there are numC colors distinct?
  int numColorAssign = numC;
  for(int i = 0; i < n;) {
    if(l[i] != numC) {
      // cannot see any other color
      if(numColorAssign-- == 0) return false;
      i++;
      continue;
    }
    // must be present with at least one other color
    break;
  }
  int nonunique = 0;
  for(int i = 0; i < n; i++) if(l[i] == numC) nonunique++;
  // do we have colors left to assign?
  if(numColorAssign == 0 && nonunique) return false;
  // does there exist a partition of nonunique of size numColorAssign
  // where each elem has size >= 2?
  if(nonunique < 2 * numColorAssign) return false;
  nonunique -= 2 * numColorAssign;
  // vacuously true?
  return true;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  sort(l, l+n);
  if(l[n-1] - l[0] <= 1 && (can(l[n-1]) || can(l[0]+1))) cout << "Yes\n";
  else cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
