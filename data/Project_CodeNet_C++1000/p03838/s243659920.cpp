#include <algorithm>
#include <cstdio>
using namespace std;
int s(int x, int y) {
  if (x <= y)
    return y - x;
  else
    return x - y + 2;
}
int main() {
  int x, y, res = 2000000000;
  scanf("%d %d", &x, &y);
  res = min(res, s(x, y));
  res = min(res, s(-x, y) + 1);
  res = min(res, s(x, -y) + 1);
  res = min(res, s(-x, -y) + 2);
  printf("%d\n", res);
  return 0;
}
