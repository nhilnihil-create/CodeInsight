#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

struct Node {
  int i;
  int v;

  Node(int i = -1, int v = -1) {
    this->i = i;
    this->v = v;
  }

  bool operator>(const Node &n) const {
    return v < n.v;
  }
};

int main() {
  int N;
  cin >> N;
  vector<int> A;
  priority_queue <Node, vector<Node>, greater<Node> > pque;
  priority_queue <int, vector<int>, greater<int> > ids;

  ll sum = 0;
  int a;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    sum += a;
    pque.push(Node(i, a));
  }

  ll ans[N];
  memset(ans, 0, sizeof(ans));
  vector<Node> checked;

  while (!pque.empty()) {
    Node cand = pque.top();
    ids.push(cand.i);
    checked.push_back(cand);
    pque.pop();

    while (!pque.empty() && pque.top().v == cand.v) {
      Node node = pque.top();
      pque.pop();
      checked.push_back(node);
      ids.push(node.i);
    }

    int id = ids.top();
    // fprintf(stderr, "id = %d\n", id);

    if (pque.empty()) {
      ans[id] += sum;
    } else {
      int diff = cand.v - pque.top().v;
      ll cnt = diff * ids.size();
      ans[id] += cnt;
      sum -= cnt;
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << ans[i] << endl;
  }

  return 0;
}
