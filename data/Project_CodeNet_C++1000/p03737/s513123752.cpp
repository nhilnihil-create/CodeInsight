#include <stdio.h>
#include <string.h>

int main() {
  char str[255];
  scanf("%[^\n]", str);

  printf("%c", str[0] - 32);

  for(int i = 1; str[i] != '\0'; i++) {
    if(str[i] == ' ') {
      printf("%c", str[i+1] - 32);
    }
  }

  puts("");
  return 0;
}

