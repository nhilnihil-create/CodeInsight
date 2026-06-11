#include <stdio.h>
#include <string.h>

int main() {
  char str[255];
  scanf("%[^\n]", str);
  int count = 0;

  for(int i = 0; str[i] != '\0'; i++) {
    if(str[i] == ' ' && str[i+1] == str[i-1]) {
      count++;
    }
  }

  (count == 2) ? puts("YES") : puts("NO");
  return 0;
}

