#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll maxn = 100000 + 10;

ll n, m, a[maxn], b[maxn], vis[maxn], d[maxn], ans[maxn];
ll k;

int main() {
  scanf("%lld", &n);
  for(ll i = 1, sum = 0;i <= n;i ++) {
    scanf("%lld", &a[i]);
    a[i] -= sum;
    sum += a[i];
    b[i] = i;
  }
  scanf("%lld%lld", &m, &k);
  for(ll i = 1;i <= m;i ++) {
    ll x; scanf("%lld", &x);
    swap(b[x],b[x + 1]);
  }
  for(ll i = 1, tot;i <= n;i ++) {
    if(!vis[i]) {
      tot = 0;
      for(ll j = i;!vis[j];j = b[j]) {
      	vis[j] = 1;
      	d[++ tot] = j;
      }
      for(ll j = 1;j <= tot;j ++) {
        ans[d[j]] = a[d[(j + k - 1) % tot + 1]];
	  }
	}
  }
  for(ll i = 1;i <= n;i ++) {
    ans[i] += ans[i - 1];
    printf("%lld.0\n", ans[i]);
  }
  return 0;
}