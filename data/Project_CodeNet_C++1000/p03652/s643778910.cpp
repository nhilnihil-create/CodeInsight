#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
queue<int> Q[301];
int main() {
  ios::sync_with_stdio(false);
  int N, M, A;
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cin >> A;
      Q[i].push(A);
    }
  }
  int ret = 400;
  set<int> removed;
  for (int i=0; i<M; i++) {
    map<int, int> m;
    for (int j=0; j<N; j++) {
      int k = Q[j].front();
      while(removed.find(k) != removed.end()) {
        Q[j].pop();
        k = Q[j].front();
      }
      m[k]++;
    }
    int d = 0;
    int idx = 0;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
      if (d < it->second) {
        d = it->second;
        idx = it->first;
      }
    }
    //cout << idx << ' ' << d << endl;
    ret = min(ret, d);
    removed.insert(idx);
  }
  cout << ret << endl;
}