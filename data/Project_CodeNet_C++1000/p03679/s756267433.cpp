#include <bits/stdc++.h>

using namespace std;

int main()
{
  int x, a, b;

  scanf("%d %d %d", &x, &a, &b);

  if (b - a <= 0)
  {
    printf("delicious");
  }
  else if (b - a <= x)
  {
    printf("safe");
  }
  else
  {
    printf("dangerous");
  }
}