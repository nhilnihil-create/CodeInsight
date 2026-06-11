#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL a[204014], b[204014], c[204014], d[204014];
int book[204014];

LL get_f(LL f[], int x);

int main(){
  int n, k, l, i, u, v, t1, t2, id;
  while(~scanf("%d %d %d", &n, &k, &l)){
    for(i = 1; i <= n; i++){
      a[i] = b[i] = i;
    }
    for(i = 0; i < k; i++){
      scanf("%d %d", &u, &v);
      t1 = get_f(a, u);
      t2 = get_f(a, v);
      if(t1 != t2) a[t2] = t1;
    }

    for(i = 0; i < l; i++){
      scanf("%d %d", &u, &v);
      t1 = get_f(b, u);
      t2 = get_f(b, v);
      if(t1 != t2) b[t2] = t1;
    }

    LL e = n+1;
    for(i = 1; i <= n; i++){
      ///c[i] = a[i] + e*b[i];
      c[i] = get_f(a, i) + e*get_f(b, i);
      d[i] = c[i];
    }

    sort(d+1, d+1+n);
    memset(book, 0, sizeof(book));
    for(i = 1; i <= n; i++){
      id = lower_bound(d+1, d+1+n, c[i]) - d;
      book[id]++;
    }
    for(i = 1; i <= n; i++){
      id = lower_bound(d+1, d+1+n, c[i]) - d;
      printf("%d%c", book[id], i == n? '\n': ' ');
    }
  }
  return 0;
}
LL get_f(LL f[], int x){
  if(x == f[x]) return f[x];
  return f[x] = get_f(f, f[x]);
}
