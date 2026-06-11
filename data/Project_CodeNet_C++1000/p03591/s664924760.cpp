#include <cstdio>
#include <cstring>

int main()
{
  char s[11];
  scanf("%s", s);
  puts(memcmp(s, "YAKI", 4) == 0 ? "Yes" : "No");
  return 0;
}