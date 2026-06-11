#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 2;

int fir[N] , ne[M] , to[M] , cnt , dp[N] , n , m  , x , y , du[N]  , A[N] , fa[N];

void add(int x , int y) {
  ne[++ cnt] = fir[x];
  fir[x] = cnt;
  to[cnt] = y;
  ++ du[x];
}

void link(int x , int y) {
  add(x , y);
  add(y , x);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

void dfs(int x , int f) {
  fa[x] = f;
  Foreachson(i , x) {
    int V = to[i];
    if(V == f)
      continue;
    A[x] -= A[V];
    dfs(V , x);
  }
}

#define Cannot exit(puts("NO") * 0)

void calc(int x , int f) {
  if(du[x] == 1) {
    dp[x] = A[x];
    return;
  }

  if(A[x] > 0) {
    Cannot;
  }

  vector <int> cxt;
  cxt.clear();
  
  Foreachson(i , x) {
    int V = to[i];
    if(V == f)
      continue;
    calc(V , x);
    cxt.push_back(dp[V]);
  }
  sort(cxt.begin() , cxt.end());
  int now = 0;
  for(int i = 0;i < (int) cxt.size() - 1;++ i) {
    now = now + cxt[i];
  }
  if(now + cxt.back() >= (-A[x]) * 2 && now >= (-A[x])) {
    dp[x] = now + cxt.back() + A[x] * 2;
    A[fa[x]] -= A[x];
  }
  else Cannot;
}

int main() {
  scanf("%d" , &n);
  for(int i = 1;i <= n;++ i)
    scanf("%d" , &A[i]);
  for(int i = 1;i < n;++ i) {
    scanf("%d%d" , &x , &y);
    link(x , y);
  }
  if(n == 2) {
    if(A[1] == A[2])
    puts("YES");
    else Cannot;
    return 0;
  }
  int rt = 0;
  for(int i = 1;i <= n;++ i) {
    if(du[i] >= 2) {
      rt = i;
      break;
    }
  }
  dfs(rt , 0);
  calc(rt , 0);
  if(dp[rt]) Cannot;
  puts("YES");
}
