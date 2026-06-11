#include <vector>
#include <stdio.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    p[i]--;
  }

  
  bool pre = p[0] == 0? true: false;
  int ans = pre;
  for (int i = 1; i < n; ++i) {
    if (p[i] == i && !pre) ans++;
    if (p[i] == i && !pre) {
      pre = true;
    } else {
      pre = false;
    }
    // pre = p[i] == i;
  }

  printf("%d\n", ans);
  return 0;
}

