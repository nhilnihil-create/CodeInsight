#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int a, b, c, d, e, f, p, q; long double l = 0;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  rep(i, f/100){
    bool g = 0;
    rep(j, (i+1)/b+1){
      if(i+1-j*b >= 0 && (i+1-j*b)%a == 0){
        g = 1;
        break;
      }
    }
    if(g){
      rep(j, min((i+1)*e+1, f-i*100-100+1)){
        bool h = 0;
        rep(k, j/d+1){
          if(j-k*d >= 0 && (j-k*d)%c == 0){
            h = 1;
            break;
          }
        }
        if(h && l*(i+1) <= j){
          p = i*100+100;
          q = j;
          long double m = j;
          l = m/(i+1);
          if(l == e) break;
        }
      }
    }
  }
  printf("%d %d\n", p+q, q);
  return 0;
}
