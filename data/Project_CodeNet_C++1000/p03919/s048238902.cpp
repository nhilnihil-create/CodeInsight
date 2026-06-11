#include <stdio.h>
#include <string.h>

int main(void) {
  int i, j, k, h, w;
  char s[10];
  scanf("%d%d", &h, &w);
  for(i = 0; i < h; ++i) for(j = 0; j < w; ++j) {
    scanf("%s", s);
    if(!strcmp(s, "snuke")) printf("%c%d", j + 'A', i + 1);
  }
  return 0;
}