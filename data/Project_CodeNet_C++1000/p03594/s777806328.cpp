#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, w, d;
  scanf("%d %d %d", &h, &w, &d);
  if (d & 1) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if ((i + j) & 1) printf("R");
        else printf("G");
      }
      printf("\n");
    }
  } else {
    int before = d / 2;
    int beforeDelta = -1;
    char firstRB;
    char secondRB;
    char firstGY = 'G';
    char secondGY = 'Y';
    for (int i = 0; i < h; i++) {
      if (i % (2 * d) < d) {
        firstRB = 'R';
        secondRB = 'B';
      } else {
        firstRB = 'B';
        secondRB = 'R';
      }

      if (i % (2 * d) < d / 2 || i % (2 * d) > 3 * d / 2) {
        firstGY = 'G';
        secondGY = 'Y';
      } else {
        firstGY = 'Y';
        secondGY = 'G';
      }

      int numFirstRB = d - 2 * before;
      for (int j = 0, cur = 0; j < w; j++) {
        if (j < before) printf("%c", secondGY);
        else {
          if (cur < numFirstRB) printf("%c", firstRB);
          else printf("%c", firstGY);
          cur++;
          if ((j - before + 1) % d == 0) swap(firstGY, secondGY);
          if (cur == d) {
            cur = 0;
            swap(firstRB, secondRB);
          }
        }
      }

      printf("\n");
      before += beforeDelta;
      if (before < 0) {
        before = 1;
        beforeDelta = 1;
      } else if (before > d / 2) {
        before = d / 2 - 1;
        beforeDelta = -1;
      }
    }
  }
  return 0;
}
