#include <iostream>
#include <locale>

int main () {
  char s1[10], s2[10], s3[10];
  
  std::cin >> s1 >> s2 >> s3;
  
  putchar(toupper(s1[0]));
  putchar(toupper(s2[0]));
  putchar(toupper(s3[0]));
}