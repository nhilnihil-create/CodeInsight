#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

long long N;
int T = 1;
deque<int> L, R;

void f(long long x) {
  if (x == 0) return;
  else if (x % 2 == 0) {
    f(x-1);
    int t = T++;
    L.push_back(t);
    R.push_front(t);
  }
  else {
    f(x/2);
    int t = T++;
    L.push_back(t);
    R.push_back(t);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  f(N);
  int l = L.size() + R.size();
  if (l > 200) return 1;
  cout << l << "\n";
  for (int x : L) cout << x << " ";
  for (int x : R) cout << x << " "; cout << "\n";
  return 0;
}
