#include <cstdio>
#include <string>
using i64 = long long;

bool ask(i64 n) {
  printf("? %lld\n", n);
  fflush(stdout);
  char res[10];
  scanf("%s", res);
  return res[0] == 'Y';
}

int main() {
  int c = 0, t = 1;

  for (; c <= 9; c++) {
    if (!ask(t)) break;
    t *= 10;
  }

  if (c == 10) {
    i64 t = 10;
    while (!ask(t - 1)) t *= 10;
    printf("! %lld\n", t / 10);
  } else {
    i64 ret = 0;
    for (int i = 1; i < c; i++) {
      int l = 0, r = 10;
      while (r - l > 1) {
        const int mid = (l + r) / 2;
        if (ask(ret * 10 + mid)) l = mid;
        else r = mid;
      }

      ret = ret * 10 + l;
    }

    ret *= 10;

    int l = -1, r = 9;
    while (r - l > 1) {
      const int mid = (l + r) / 2;
      if (ask((ret + mid) * 10)) r = mid;
      else l = mid;
    }

    printf("! %lld\n", ret + r);
  }

  fflush(stdout);

  return 0;
}
