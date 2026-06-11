#include <cstdio>
#include <cstring>

int main()
{
  char s[100001];
  scanf("%s", s);
  int l = 0, r = strlen(s) - 1;
  if ((r & 1) == 0)
  {
    puts("No");
    return 0;
  }
  while (l < r)
  {
    if (s[l] == 'b' && s[r] == 'd' ||
        s[l] == 'd' && s[r] == 'b' ||
        s[l] == 'p' && s[r] == 'q' ||
        s[l] == 'q' && s[r] == 'p')
    {
      ++l;
      --r;
      continue;
    }
    puts("No");
    return 0;
  }
  puts("Yes");
  return 0;
}
    