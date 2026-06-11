#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) if (scanf("%d", &v)<1);
#define in_s(v) if (scanf("%s", v)<1);
#define out(v) printf("%d\n", v)
const int S = 1, W = 2, EMPTY = -1;

int main() {
  int N; in(N);
  char s[N]; in_s(s);

  int v[N];
  rep(first, 2) rep(second, 2) {
    fill(v, v+N, EMPTY);
    v[0] = first ? W : S;
    v[1] = second ? W : S;
    bool matched = true;
    rep(i, N) {
      int l = i, mid = (i+1)%N, r = (i+2)%N;
      if (s[mid] == 'o' && v[mid] == S || s[mid] == 'x' && v[mid] == W) {
        if (v[r] == EMPTY)
          v[r] = v[l];
        else if (v[r] != v[l]) {
          matched = false;
          break;
        }
      } else {
        if (v[r] == EMPTY)
          v[r] = v[l] == S ? W : S;
        else if (v[r] == v[l]) {
          matched = false;
          break;
        }
      }
    }
    if (matched) {
      rep(i, N)
        printf("%c", v[i] == S ? 'S' : 'W');
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");

  return 0;
}
