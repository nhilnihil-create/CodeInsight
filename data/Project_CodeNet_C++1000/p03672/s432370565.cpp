#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char str[222];
  cin >> str;
  int n = strlen(str);
  for (int i=n-2; i; i-=2) {
    if (strncmp(str, str+i/2, i/2)==0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}