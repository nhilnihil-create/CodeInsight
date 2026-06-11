#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100000];
vector<int> path;

bool search(int cur, int dst, int parent) {
  if (cur == dst) {
    return true;
  }
  for (auto to: g[cur]) {
    if (to == parent) {
      continue;
    }
    bool result = search(to, dst, cur);
    if (result) {
      if (parent != -1) {
        path.push_back(cur);
      }
      return true;
    }
  }
  return false;
}
int main() {
  cin>>n;
  for (int i=0; i<n-1; i++) {
    int a, b;
    cin>>a>>b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  search(0, n-1, -1);
  reverse(path.begin(), path.end());
  int color[n];
  for (int i=0; i<n; i++) color[i] = 0;
  color[0] = 1;
  color[n-1] = -1;
  for (int i=0; i<path.size(); i++) {
    if (i <= (path.size() - 1)/ 2) {
      color[path[i]] = 1;
    } else {
      color[path[i]] = -1;
    }
  }
  for (int i=0; i<n; i++) {
    if (color[i] == 0) {
      continue;
    }
    int c = color[i];
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto to: g[node]) {
        if (color[to] == 0) {
          color[to] = c;
          q.push(to);
        }
      }
    }
  }
  int sum = 0;
  for (int i=0; i<n; i++) sum += color[i];
  if (sum > 0) {
    cout<<"Fennec"<<endl;
  } else {
    cout<<"Snuke"<<endl;
  }
}