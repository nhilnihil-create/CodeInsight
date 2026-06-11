#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool p = false;
  if (a + b == c) p = true;
  if (b + c == a) p = true;
  if (c + a == b) p = true;
  if (p) printf("Yes\n");
  else printf("No\n");
  return 0;
}