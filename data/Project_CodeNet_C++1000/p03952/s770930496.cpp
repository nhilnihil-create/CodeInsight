#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x; scanf("%d %d",&n, &x);
  if (x==1 || x==2*n-1) {
    puts("No");
  } else {
    puts("Yes");
    for (int i = 0; i < 2*n-1; i++) {
      printf("%d\n", (x-n+2*n+i-1)%(2*n-1)+1);
    }
  }
  return 0;
}
