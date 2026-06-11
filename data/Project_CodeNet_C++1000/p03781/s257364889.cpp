#include<bits/stdc++.h>
#define fo(i, n) for(int i = 1; i <= (n); i ++)
using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
  x = 0;char c = getchar();bool f = 0;
  for(; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
  for(; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
  if(f) x = -x;
}

int n, ans = 0;
main(void) {
  read(n);
  for(int i = 1; i <= n; i ++) {
    ans += i;
    if(ans >= n) {cout << i << "\n"; break;}
  }
}
