#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> G[100000];
bool used[100000];

bool rec(int from, vector<int>& v) {
  if (used[from]) return false;
  used[from] = true;
  v.push_back(from);
  for (int to : G[from]) {
    bool res = rec(to, v);
    if (res) return true;
  }
  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  vector<int> v;
  rec(0, v);
  reverse(v.begin(), v.end());
  v.pop_back();
  used[0] = false;
  rec(0, v);
  
  cout << v.size() << endl;
  for (int i : v) {
    cout << i + 1 << ' ';
  }
  cout << endl;
}