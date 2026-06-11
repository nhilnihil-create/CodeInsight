#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int INF = 10000000;
  string S;
  cin >> S;
  int N = S.size();
  int Nex[26];
  int Next[N][26];
  vector<int> Prev[N];
  int dis[N];
  queue<P> que;
  for (int i = 0; i < N; i++) {
    dis[i] = INF;
  }
  // dis : 詰みまでの距離
  // 次でつむとき,0
  for (int i = 0; i < 26; i++) {
    Nex[i] = INF;
  }
  for (int i = N-1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      Next[i][j] = Nex[j];
    }
    Nex[S[i] - 'a'] = i;
  }

  for (int i = 0; i < 26; i++) {
    if (Nex[i] == INF) {
      cout << (char)('a' + i) << endl;
      return 0;
     }
   }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 26; j++) {
      if (Next[i][j] != INF) {
        Prev[Next[i][j]].push_back(i);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    bool T = false;
    for (int j = 0; j < 26; j++) {
      if (Next[i][j] == INF) {
        T = true;
      }
    }
    if (T) {
      que.push(make_pair(0,i));
    }
  }

  while (!que.empty()) {
    P p = que.front();
    que.pop();
    if (dis[p.S] <= p.F) {
      continue;
    }
    dis[p.S] = p.F; 
    for (int i = 0; i < (int)Prev[p.S].size(); i++) {
      if (dis[Prev[p.S][i]] > p.F + 1) {
        que.push(make_pair(p.F+1,Prev[p.S][i]));
      }
    }
  }
  string ans = "";
  int now = -1;
  int pos = -1;
  while (0 == 0) {
    int mx = INF;
    char c;
    pos = -1;
    if (now == -1) {
      for (int i = 0; i < 26; i++) {
        if (mx > dis[Nex[i]]) {
          mx = dis[Nex[i]];
          pos = Nex[i];
          c = i + 'a';
        }
      }
    } else {
      for (int i = 0; i < 26; i++) {
        if (mx > dis[Next[now][i]]) {
          mx = dis[Next[now][i]];
          pos = Next[now][i];
          c = i + 'a';
        }
      }
    }
    now = pos;
    ans += c;
    if (mx == 0) {
      break;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (Next[now][i] == INF) {
      ans += 'a' + i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}