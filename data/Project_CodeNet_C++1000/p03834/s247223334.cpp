#include <stdio.h>

int main() {
  char s[20];
  scanf("%[^\n]", s);

  for(int i = 0; s[i] != '\0'; i++) {
    if(s[i] == ',') {
      printf(" ");
      continue;
    }
    printf("%c", s[i]);
  }
  return 0;
}