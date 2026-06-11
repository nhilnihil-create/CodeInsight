#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Verified: AOJ-DSL1A
class UFSet {
 private:
  vector<int> ranks;
  vector<int> prevs;

 public:
  UFSet(int n) : ranks(n), prevs(n) {
    for (int i = 0; i < n; i++) prevs[i] = i;
  }

  // Returns a root of a tree which x belongs to.
  int Find(int x) {
    if (x != prevs[x]) prevs[x] = Find(prevs[x]);
    return prevs[x];
  }

  // Merges a set which x blongs to and a set which y belongs to.
  void Union(int x, int y) {
    int x_root = Find(x);
    int y_root = Find(y);
    if (ranks[x_root] > ranks[y_root]) {
      prevs[y_root] = prevs[x_root];
    } else if (ranks[x_root] < ranks[y_root]) {
      prevs[x_root] = prevs[y_root];
    } else if (prevs[x_root] != prevs[y_root]) {
      prevs[y_root] = prevs[x_root];
      ranks[x_root]++;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k, l;
  cin >> n >> k >> l;

  UFSet ufs1(n);
  UFSet ufs2(n);
  for (int i = 0; i < k; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    ufs1.Union(v1, v2);
  }
  for (int i = 0; i < l; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    ufs2.Union(v1, v2);
  }

  map<pair<int, int>, int> m;
  for (int i = 0; i < n; i++) {
    int c1 = ufs1.Find(i);
    int c2 = ufs2.Find(i);
    m[make_pair(c1, c2)]++;
  }

  for (int i = 0; i < n; i++) {
    int c1 = ufs1.Find(i);
    int c2 = ufs2.Find(i);
    cout << m[make_pair(c1, c2)] << " ";
  }
  cout << endl;
}