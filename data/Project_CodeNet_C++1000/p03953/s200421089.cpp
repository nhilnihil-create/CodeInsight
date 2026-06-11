#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
int n,m,p[N],per[N],vis[N],ans[N],lop[N],cnt;
ll k,val[N],res[N];
int main() {
  scanf("%d",&n);
  for (int i = 1 ; i <= n ; ++ i)
    scanf("%lld",&val[i]);
  scanf("%d%lld",&m,&k);
  for (int i = 1 ; i <= m ; ++ i)
    scanf("%d",&p[i]);
  for (int i = n ; i >= 1 ; -- i)
    val[i] = val[i] - val[i-1];
  for (int i = 1 ; i <= n ; ++ i)
    per[i] = i;
  for (int i = 1 ; i <= m ; ++ i)
    swap(per[p[i]],per[p[i]+1]);
  for (int i = 1 ; i <= n ; ++ i) {
    if (vis[i]) continue;
    cnt = 0;
    lop[++cnt] = i;
    int pos = per[i];
    while (pos != i) {
      vis[pos] = 1;
      lop[++cnt] = pos;
      pos = per[pos];
    }
    for (int j = 1 ; j <= cnt ; ++ j)
      ans[lop[j]] = lop[(j + k - 1) % cnt + 1];
  }
  for (int i = 1 ; i <= n ; ++ i)
    res[i] = val[ans[i]];
  for (int i = 1 ; i <= n ; ++ i)
    res[i] += res[i-1];
  for (int i = 1 ; i <= n ; ++ i)
    printf("%lld.0\n",res[i]);
  return 0;
}