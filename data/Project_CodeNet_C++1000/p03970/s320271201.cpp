#include <cstdio>

const char f[] = "CODEFESTIVAL2016";

int main()
{
  char s[17];
  scanf("%s", s);
  int ans = 0;
  for (int i = 0; i < 16; ++i)
  {
    if (s[i] != f[i]) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}