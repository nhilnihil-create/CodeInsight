#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  if(y - x >= 0)
    printf("%d\n", min(y - x, abs(x + y) + 1));
  else
    printf("%d\n", min(x - y + 2, abs(x + y) + 1));
}