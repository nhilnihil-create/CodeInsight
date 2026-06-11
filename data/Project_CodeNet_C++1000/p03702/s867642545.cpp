#include<cstdio>
#include<algorithm>
#define MAX 100005
#define MAXH 1000000005
using namespace std;
 
int main(){
  long long n, a, b, h[MAX], l, r, mid, i, c, d;
  scanf("%lld%lld%lld", &n, &a, &b);
  for(i = 0; i < n; i++) scanf("%lld", &h[i]);
  l = 0; r = MAXH;
  while(r - l > 1){
    mid = (l + r) / 2;
    c = 0;
    for(i = 0; i < n; i++){
      d = h[i] - b * mid;
      if(d > 0) c += (d - 1) / (a - b) + 1;
    }
    if(c <= mid) r = mid;
    else l = mid;
  }
  printf("%lld", r);
}