#include <cstdio>
using namespace std;

int main() {
  int a,b;
  char f;
  scanf("%d %c %d",&a,&f,&b);
  if (f == '+') printf("%d\n",a+b);
  else printf("%d\n",a-b);
  return 0;
}