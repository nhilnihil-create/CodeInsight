#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a, b;
char s[N];

int main() {
  cin >> n >> a >> b;
  cin >> s + 1;
  int cur = 0, os = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'a') {
      if (cur < a + b) {
        cur++;
        printf("Yes\n");
      }
      else printf("No\n");
    }
    else if (s[i] == 'b') {
      if (cur < a + b && os < b) {
        os++;
        cur++;
        printf("Yes\n");
      }
      else printf("No\n");
    }
    else {
      printf("No\n");
    }
  }
  return 0;
}
