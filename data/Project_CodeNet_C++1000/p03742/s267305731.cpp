#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
int main() {
  scanf("%lld%lld",&x,&y);
  if (abs(y - x) <= 1) puts("Brown");
  else puts("Alice");
  return 0;
}