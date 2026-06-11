#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a[13] = {0,
               1,
               2,
               1,
               3,
               1,
               3,
               1,
               1,
               3,
               1,
               3,
               1};

  int x, y;

  scanf("%d %d", &x, &y);

  printf(a[x] == a[y] ? "Yes" : "No");
}