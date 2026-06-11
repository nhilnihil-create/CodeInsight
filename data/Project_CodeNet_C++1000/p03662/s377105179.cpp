#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int D[101000], D2[101000], n;
vector<int>E[101000];
void DFS(int a, int pp, int d) {
  D[a] = d;
  int i;
  for (i = 0; i < E[a].size(); i++) {
    if (E[a][i] != pp)DFS(E[a][i], a, d + 1);
  }
}
int main() {
  int i, a, b;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  DFS(n, 0, 0);
  for (i = 1; i <= n; i++)D2[i] = D[i];
  DFS(1, 0, 0);
  int r1 = 0, r2 = 0;
  for (i = 1; i <= n; i++) {
    if (D[i] <= D2[i])r1++;
    else r2++;
  }
  if (r1 > r2)printf("Fennec\n");
  else printf("Snuke\n");
}
