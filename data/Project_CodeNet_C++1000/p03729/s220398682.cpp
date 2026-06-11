#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if(a.back() == b.front() && b.back() == c.front())
    printf("YES\n");
  else
    printf("NO\n");
}