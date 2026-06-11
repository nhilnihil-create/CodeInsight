#include <stdio.h>

int main() {
  char s[11];
  scanf("%s", s);

  int idx = 0;
  for(int i = 0; s[i] != '\0'; i++) {
    if(s[i] == '0') s[idx++] = '0';
    else if(s[i] == '1') s[idx++] = '1';
    else if(s[i] == 'B' && idx > 0) idx--;
  }

  for(int i = 0; i < idx; i++) {
    printf("%c", s[i]);
  }
  return 0;
}