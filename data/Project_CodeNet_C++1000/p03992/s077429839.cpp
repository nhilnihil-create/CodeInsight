#include <cstdio>

int main()
{
  char s[13];
  scanf("%s", s);
  printf("%.*s %.*s\n", 4, s, 8, s + 4);
  return 0;
}