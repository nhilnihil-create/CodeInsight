#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int x[111111];
vector<int> y[111111];
int z[111111];

int test() {
  /*
  vector<int> v;
  
  for (int i = 0; i < n; i++) {
    v.push_back(x[i]);
  }

  int res = 0;
  do {
  for (int i = 0; i < n-1; i++) {
  }
  } while(next_permutation(v.begin(), v.end()));
  */
}

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", x+i);
    y[x[i]%m].push_back(x[i]);
  }

  int res = 0;
  memset(z, -1, sizeof(z));
  for (int i = 0; i < m; i++) {
    if (z[i] >= 0) continue;
    int p = i;
    int q = (m-i)%m;
    if (p == q) {
      z[p] = y[p].size();
      res += z[p]/2;
    } else {
      z[p] = z[q] = min(y[p].size(), y[q].size());
      res += z[p];
    }
  }

  for (int i = 0; i < m; i++) {
    sort(y[i].begin(), y[i].end());
    // printf("%d/%zd\n", z[i], y[i].size());
    for (int j = 0; j < int(y[i].size())-1; j++) {
      if (y[i][j] == y[i][j+1] && z[i]+2 <= int(y[i].size())) {
        z[i] += 2;
        res += 1;
        j++;
      }
    }
  }
  
  printf("%d\n", res);
  return 0;
}
