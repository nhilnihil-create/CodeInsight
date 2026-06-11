#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
// age, distance, v, from, color
typedef tuple<int, int, int, int, int> ituple;
priority_queue<ituple> q;

// const int INF = INT_MAX;
// const ll INF = LLONG_MAX;
// const int MOD = ((int)1e9 + 7);
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (100000 + 2)
VI edge[MAX_N];
map<ipair, int> memo;
int colors[MAX_N];
int ages[MAX_N];
int vv[MAX_N];
int dd[MAX_N];
int cc[MAX_N];
int distances[MAX_N];

void exec(){
  int n, m, Q, a, b, tmp_v, tmp_d, tmp_c;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++){
    scanf("%d%d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  for (int i = 0; i < MAX_N; i++){
    distances[i] = -1;
  }

  scanf("%d", &Q);
  for (int j = 1; j <= Q; j++){
    scanf("%d%d%d", &vv[j], &dd[j], &cc[j]);
  }
  for (int j = Q; j >= 1; j--){
    q.push(ituple(j, dd[j], vv[j], -1, cc[j]));

    while (!q.empty()) {
      ituple e = q.top();
      q.pop();

      int v = get<2>(e);
      int from = get<3>(e);
      int d = get<1>(e);
      int age = get<0>(e);
      int color = get<4>(e);

      // printf("v = %d, from = %d, d = %d, age = %d, color = %d\n", v, from, d, age, color);

      if (distances[v] != -1 && d <= distances[v]) {
        continue;
      }

      if (ages[v] == 0 || ages[v] < age) {
        ages[v] = age;
        colors[v] = color;
      }

      distances[v] = d;

      if (d == 0) {
        continue;
      }

      for (int i = 0; i < edge[v].size(); i++){
        if (edge[v][i] == from) {
          continue;
        }

        q.push(ituple(age, d - 1, edge[v][i], v, color));
      }

    }
  }

  for (int i = 1; i <= n; i++){
    printf("%d\n", colors[i]);
  }

}

void solve(){
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; i++){
    exec();
  }
}

int main(){
  solve();
  return 0;
}
