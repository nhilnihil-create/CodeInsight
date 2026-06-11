#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int n, m;

int calc_best_sports(vector<queue<int>>& la, vector<bool>& removed) {
  vector<int> count(m, 0);
  for (int i = 0; i < n; ++i) { 
    if (la[i].empty()) return -1;
    int s = la[i].front();
    while (removed[s]) {
      la[i].pop();
      if (la[i].empty()) break;
      s = la[i].front();
    }
    if (la[i].empty()) return -1;
    if (removed[s]) continue;
    ++count[s];
  }
  int best = 0;
  int sports = -1;
  for (int i = 0; i < m; ++i) { 
    // cerr << "[r]" << i << " " << removed[i] << endl;
    if (best < count[i]) {
      best = count[i];
      sports = i;
    }
  }
  for (int i = 0; i < n; ++i) { 
    while (!la[i].empty()) {
      int s = la[i].front();
      if (s != sports && !removed[s]) break;
      la[i].pop();
    }
  }
  if (sports == -1) return -1;
  removed[sports] = true;
  // cerr << sports << " " << best << endl;
  return best;
};

int main() {
  cin >> n >> m;
  vector<queue<int>> la;
  vector<bool> removed(m, false);
  for (int i = 0; i < n; ++i) { 
    queue<int> tmp;
    for (int j = 0; j < m; ++j) { 
      int a;
      cin >> a;
      --a;
      tmp.push(a);
    }
    la.push_back(tmp);
  }
  int ans = n;
  while (true) {
    int best = calc_best_sports(la, removed);
    if (best == -1) break;
    ans = min(ans, best);
  }
  cout << ans << endl;
  return 0;
}
