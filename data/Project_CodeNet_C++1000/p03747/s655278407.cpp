#include<bits/stdc++.h>
#define mx 100005
using namespace std;

int n, l, t, w, s[2], u[2];
long long nw[mx], cnt, x;

int main(){
  scanf("%d%d%d", &n, &l, &t);
  s[0] = t % l;
  s[1] = l - s[0];
  u[0] = t / l;
  u[1] = - 1 - u[0];
  for(int i = 0; i < n; i++){
    scanf("%lld%d", &x, &w);
    w--; x += s[w];
    nw[i] = x % l;
    cnt += u[w] + x / l;
  }
  while(cnt < 0) cnt += n;
  sort(nw, nw+n);
  rotate(nw, nw + cnt%n, nw+n);
  for(int i = 0; i < n; i++) {
    printf("%lld\n", nw[i]);
  }
}