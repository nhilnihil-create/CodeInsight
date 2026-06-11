#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int N,M,Q;
vector<int> Graph[110000];
vector<int> mx(110000);
vector<int> ans(110000);

struct q {
  int v;
  int d;
  int c;
};

void query(int v,int d,int c) {
  queue<P> que;
  que.push(make_pair(v,d));
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    if (p.S < 0) {
      break;
    }
    if (mx[p.F] >= p.S) {
      continue;
    } else {
      mx[p.F] = p.S;
    }

    if (ans[p.F] == -1) {
      ans[p.F] = c;
    }
    
    for (int i = 0; i < (int)Graph[p.F].size(); i++) {
      int s = Graph[p.F][i];
      que.push(make_pair(s,p.S-1));
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }
  cin >> Q;
  vector<q> querys(Q);
  for (int i = 0; i < Q; i++) {
    cin >> querys[i].v >> querys[i].d >> querys[i].c;
    querys[i].v--;
  }
  reverse(querys.begin(),querys.end());
  for (int i = 0; i < N; i++) {
    mx[i] = -1; ans[i] = -1;
  }
  for (int i = 0; i < Q; i++) {
    query(querys[i].v,querys[i].d,querys[i].c);
  }
  for (int i = 0; i < N; i++) {
    if (ans[i] == -1) {
      cout << 0 << endl;
    } else {
      cout << ans[i] << endl;
    }
  }
  return 0;
}