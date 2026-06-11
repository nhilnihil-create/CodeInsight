#include<cstdio>
#include<iostream>
#include<map>
#include<utility>

using namespace std;

long long B[10];
map<pair<int, int>, int> cells;

int main() {
  int H, W;
  int N;

  scanf("%d", &H);
  scanf("%d", &W);
  scanf("%d", &N);

  for (int i = 0; i < 10; i++) {
    B[i] = 0;
  }

  int a, b;
  int len = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &a);
    scanf("%d", &b);

    for (int dx = -2; dx < 1; dx++) {
      for (int dy = -2; dy < 1; dy++) {
        bool f = false;
        int x = a + dx, y = b + dy;
        if (x <= 0 || y <= 0 || x > H - 2 || y > W - 2) continue;
        if (cells.find(make_pair(x, y)) != cells.end())
          cells[make_pair(x, y)] += 1;
        else {
          cells[make_pair(x, y)] = 1;
          len += 1;
        }

        //for (int j = 0; j < len; j++) {
        //  if (cells[j][0] == x && cells[j][1] == y) {
        //    cells[j][2] += 1;
        //    f = true;
        //    break;
        //  }
        //}
        //if (!f) {
        //  cells[len][0] = x;
        //  cells[len][1] = y;
        //  cells[len][2] = 1;
        //  len += 1;
        //}
        //printf("%d %d\n", x, y);
      }
    }
  }

  for (auto j = cells.begin(); j != cells.end(); ++j) {
    B[j->second] += 1;
  }

  B[0] = (((long long)H - 2) * ((long long)W - 2)) - len;


  for (int i = 0; i < 10; i++) {
    cout << B[i] << endl;
  }

  return 0;
}
