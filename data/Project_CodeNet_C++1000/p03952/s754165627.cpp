#include<cstdio>
using namespace std;
const int MAX = 300000 + 10;

int ans[MAX];

int main(){
  int n, x;
  scanf("%d %d", &n, &x);
  if (x == 1 || x == 2*n-1) {
    puts("No");
  } else {
    ans[n-1] = x;
    int now = n-2;
    for(int i = 1 ; i <= 2*n-1 ; i++) {
      if(i == x) continue;
      ans[now] = i;
      now--;
      if(now < 0) now = 2*n-2;
    }
    puts("Yes");
    for(int i = 0 ; i < 2 * n - 1 ; i++)
      printf("%d\n", ans[i]);
  }
  return 0;
}
