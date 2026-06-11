#include <bits/stdc++.h>

int main(void)
{
  char buf[200];
  char a[10], b[101], c[10];

  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%s %s %s", a, b, c);

  std::cout << "A" << b[0] << "C" << std::endl;

  return 0;
}