#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  scanf("%d", &n);
  set<int> a;
  for(int i = 0; i < n; i++) {
    scanf("%d", &t);
    a.insert(t);
  }
  printf("%d\n", a.size() - (a.size() + 1) % 2);
}