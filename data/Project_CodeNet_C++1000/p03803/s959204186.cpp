#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  if (a == b) {
    printf("Draw");
  }
  else if (a > b && b != 1 || a == 1)
  {
    printf("Alice");
  }
  else
  {
    printf("Bob");
  }
}