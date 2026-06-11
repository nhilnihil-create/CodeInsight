#include <stdio.h>

int main() {
  int n, x = 0, max  = 0;
  scanf("%d", &n);

  char s[n];
  scanf("%s", s);

  for(int i = 0; i < n; i++) {
    if(s[i] == 'I') {
      x++;
    }
    else if(s[i] == 'D') {
      x--;
    }
    if(max < x) {
      max  = x;
    }
  }
  printf("%d", max);
  return 0;
}