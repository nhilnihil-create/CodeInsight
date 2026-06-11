#include <cstdio>

using namespace std;

int N, M;
int occurences[100005];

int main()
{
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++)
  {
    int a, b; scanf("%d%d", &a, &b);
    occurences[a]++; occurences[b]++;
  }
  for (int i = 1; i <= N; i++)
  {
    if (occurences[i] % 2 == 1) {printf("NO\n"); return 0;}
  }
  printf("YES\n");
  return 0;
}