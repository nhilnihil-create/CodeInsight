#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x; scanf("%d %d",&n, &x);
  int d = 2*n-1;
  if (x==1 || x==d) {
    puts("No");
  } else {
    puts("Yes");
    for (int i = 0; i < d; i++) {
      printf("%d\n", (x-n+i+d)%d+1);
    }
  }
  return 0;
}
