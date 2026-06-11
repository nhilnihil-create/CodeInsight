#include <bits/stdc++.h>
using namespace std;

const int N = 110005;

int n, val[N];
vector<int> edge[N];
int num[N];

void DFS(int t);

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    edge[x].push_back(i);
  }
  DFS(1);
  printf("%d\n", val[1]);
  return 0;
}

void DFS(int t) {
  int cnt = 0;
  for (int i = edge[t].size() - 1; i >= 0; --i) DFS(edge[t].at(i));
  for (int i = edge[t].size() - 1; i >= 0; --i) num[++cnt] = val[edge[t].at(i)];
  sort(num + 1, num + cnt + 1);
  for (int i = 1; i <= cnt; ++i) 
    val[t] = max(val[t], num[i] + cnt - i + 1);
}
