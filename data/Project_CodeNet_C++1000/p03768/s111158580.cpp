/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n, m, q;
int v[N], d[N], c[N];
int color[N][11];
vector < int > g[N];

void paint(int v, int d, int T){
  color[v][d] = max(color[v][d], T);
  if(d){
    for(int i : g[v]){
      if(!color[i][d - 1]){
        paint(i, d - 1, T);
      }
    }
  }
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; ++i){
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  scanf("%d", &q);
  for(int i = 1; i <= q; ++i){
    scanf("%d %d %d", v + i, d + i, c + i);
  }
  for(int i = q; i >= 1; --i){
    paint(v[i], d[i], i);
  }
  for(int i = 1; i <= n; ++i){
    int mx = 0;
    for(int j = 0; j <= 10; ++j){
      mx = max(mx, color[i][j]);
    }
    printf("%d\n", c[mx]);
  }

  return 0;
}
