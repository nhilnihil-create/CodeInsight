#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v(3);
  for(int i = 0; i < 3; i++) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  printf("%d\n", v[0] + v[1]);
}