#include <bits/stdc++.h>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef pair<i64,int> pli;
typedef pair<int,i64> pil;
typedef pair<i64,i64> pll;
typedef vector<int> vi;
typedef vector<i64> vl;

template <typename T>
T id(T b) {return b;};
template <class It>
bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It>
bool any(It f,It l){return std::any_of(f,l,id<bool>);}

const int MAX_N = 2000;
int n,k;
vi g[MAX_N];
int dist[MAX_N][MAX_N] = {};
int cnt[MAX_N] = {};
bool out[MAX_N] = {};

void dfs(int u, int p, int r, int d) {
  dist[r][u] = d;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u, r, d+1);
  }
}

int main() {
  cin >> n >> k;
  int a,b;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int u = 0; u < n; u++)
    dfs(u, -1, u, 0);

  set<pii, greater<pii> > s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[i][j] > k) cnt[i]++;
    }
    if (cnt[i] > 0) s.insert(mp(cnt[i], i));
    else out[i] = true;
    //printf("cnt[%d]=%d\n",i,cnt[i]);
  }

  int c = 0;
  while (!s.empty()) {
    auto it = s.begin();
    int i = it->snd; s.erase(it);
    //printf("x=%d c=%d\n",it->fst,it->snd);
    out[i] = true;
    c++;
    for (int j = 0; j < n; j++) {
      if (!out[j] && dist[i][j] > k) {
        auto it2 = s.find(mp(cnt[j], j)); s.erase(it2);
        if (cnt[j] > 1)
          s.insert(mp(--cnt[j], j));
        else
          out[j] = true;
      }
    }
  }

  cout << c << endl;

  return 0;
}
